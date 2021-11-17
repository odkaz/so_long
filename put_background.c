/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:29:36 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 14:33:45 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_mlx(t_mlx_data *data, t_map map)
{
	int		res_x;
	int		res_y;

	res_x =  map.w * IMG_PIXELS;
	res_y = map.h * IMG_PIXELS;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, res_x, res_y, "So_Long");
}

void	init_player(t_mlx_data *data, int x, int y)
{
	if (data->p_x != -1 || data->p_y != -1)
	{
		exit_error("init_player : you can only place one player");
	}
	data->p_x = x;
	data->p_y = y;
}

void	put_backgroud(t_map map)
{
	t_mlx_data data;
	void	*img;
	void	*img2;
	char	*bg_path = "./srcs/ground.xpm";
	int		x;
	int		y;
	char	c;

	data.map = map;
	data.p_x = -1;
	data.p_y = -1;
	set_mlx(&data, map);
	img = xpm_to_img(bg_path, data);
	if (!img)
		exit_error("no image found");
	y = 0;
	while (y < map.h)
	{
		x = 0;
		while (x < map.w)
		{
			mlx_put_image_to_window(data.mlx, data.win, img, IMG_PIXELS * x, IMG_PIXELS * y);
			c = map.grid[y][x];
			if (ft_strchr("1ECP", c))
			{
				img2 = get_img(c, data);
				mlx_put_image_to_window(data.mlx, data.win, img2, IMG_PIXELS * x, IMG_PIXELS * y);
			}
			if (c == 'P')
			{
				init_player(&data, x, y);
			}
			x++;
		}
		y++;
	}
	mlx_hook(data.win, 17, 1L<<17, exit_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
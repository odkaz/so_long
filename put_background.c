/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:29:36 by knoda             #+#    #+#             */
/*   Updated: 2021/11/25 14:00:08 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_data(t_mlx_data *data, t_map *map)
{
	int		res_x;
	int		res_y;

	res_x = map->w * IMG_PIXELS;
	res_y = map->h * IMG_PIXELS;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, res_x, res_y, "So_Long");
	data->map = map;
	data->p_x = -1;
	data->p_y = -1;
	data->collective = 0;
	data->moves = 0;
}

void	init_player(t_mlx_data *data, int x, int y)
{
	data->p_x = x;
	data->p_y = y;
}

void	put_img(t_mlx_data data, char *path, int x, int y)
{
	char	*img;

	img = xpm_to_img(path, data);
	mlx_put_image_to_window(data.mlx, data.win, \
			img, IMG_PIXELS * x, IMG_PIXELS * y);
}

void	put_backgroud(t_map *map)
{
	t_mlx_data	data;
	int			x;
	int			y;
	char		c;

	set_data(&data, map);
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			put_img(data, "./srcs/ground.xpm", x, y);
			c = map->grid[y][x];
			if (ft_strchr("1ECP", c))
				put_img(data, get_img_path(c), x, y);
			if (c == 'P')
				init_player(&data, x, y);
			x++;
		}
		y++;
	}
	mlx_hook(data.win, 17, 1L << 17, exit_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}

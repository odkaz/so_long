/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:32:16 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 15:18:17 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(int keycode, t_mlx_data *data)
{
	(void)data;
	exit(0);
	return (keycode);
}

int	check_space(t_map map, int x, int y)
{
	printf("check x = %d, y = %d, grid = %c\n", x, y, map.grid[1][3]);
	if (x < 0 || x > map.w || y < 0 || y > map.h)
		return (0);
	if (map.grid[y][x] == '0')
		return (1);
	return (0);
}

void    update_graphics()
{

}

void    move_player(t_mlx_data *data, int x, int y)
{
	void	*img;

	data->map.grid[data->p_y][data->p_x] = '0';
	img = xpm_to_img("./srcs/ground.xpm", *data);
	mlx_put_image_to_window(data->mlx, data->win, img, IMG_PIXELS * data->p_x, IMG_PIXELS * data->p_y);
	data->map.grid[y][x] = 'P';
	img = xpm_to_img("./srcs/player.xpm", *data);
	mlx_put_image_to_window(data->mlx, data->win, img, IMG_PIXELS * x, IMG_PIXELS * y);
	data->p_x = x;
	data->p_y = y;


	update_graphics();
}

int	key_hook(int keycode, t_mlx_data *data)
{
	// int		x;
	// int		y;

	// x = -1;
	// y = -1;
	if (keycode == KEY_W && check_space(data->map, data->p_x, data->p_y - 1))
	{
		move_player(data, data->p_x, data->p_y - 1);
		printf("move up\n");
		print_map(data->map);
	}
	if (keycode == KEY_A && check_space(data->map, data->p_x - 1, data->p_y))
	{
		move_player(data, data->p_x - 1, data->p_y);
		printf("move left\n");
		print_map(data->map);
	}
	if (keycode == KEY_S && check_space(data->map, data->p_x, data->p_y + 1))
	{
		move_player(data, data->p_x, data->p_y + 1);
		printf("move down\n");
		print_map(data->map);
	}
	if (keycode == KEY_D && check_space(data->map, data->p_x + 1, data->p_y))
	{
		move_player(data, data->p_x + 1, data->p_y);
		printf("move right\n");
		print_map(data->map);
	}
	// (void)data;
	return(0);
}
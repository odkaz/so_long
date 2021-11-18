/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:32:16 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 16:33:44 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(int keycode, t_mlx_data *data)
{
	(void)data;
	exit(0);
	return (keycode);
}

void	finish_game(t_mlx_data *data)
{
	printf("total moves : %d\n", data->moves);
	printf("your score is %d\n", data->collective);
	exit(0);
}

int	check_space(t_map map, int x, int y, t_mlx_data *data)
{
	// printf("check x = %d, y = %d, grid = %c\n", x, y, map.grid[1][3]);
	if (x < 0 || x > map.w || y < 0 || y > map.h)
		return (0);
	if (map.grid[y][x] == '0')
		return (1);
	if (map.grid[y][x] == 'C')
	{
		data->collective += 1;
		return (1);
	}
	if (map.grid[y][x] == 'E')
	{
		data->moves += 1;
		finish_game(data);
		return (1);
	}
	return (0);
}

void    move_player(t_mlx_data *data, int x, int y)
{
	void	*img;

	data->moves += 1;
	printf("total moves : %d\n", data->moves);
	data->map.grid[data->p_y][data->p_x] = '0';
	img = xpm_to_img("./srcs/ground.xpm", *data);
	mlx_put_image_to_window(data->mlx, data->win, img, IMG_PIXELS * data->p_x, IMG_PIXELS * data->p_y);
	data->map.grid[y][x] = 'P';
	img = xpm_to_img("./srcs/player.xpm", *data);
	mlx_put_image_to_window(data->mlx, data->win, img, IMG_PIXELS * x, IMG_PIXELS * y);
	data->p_x = x;
	data->p_y = y;

}

int	key_hook(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_W && check_space(data->map, data->p_x, data->p_y - 1, data))
	{
		move_player(data, data->p_x, data->p_y - 1);
	}
	if (keycode == KEY_A && check_space(data->map, data->p_x - 1, data->p_y, data))
	{
		move_player(data, data->p_x - 1, data->p_y);
	}
	if (keycode == KEY_S && check_space(data->map, data->p_x, data->p_y + 1, data))
	{
		move_player(data, data->p_x, data->p_y + 1);
	}
	if (keycode == KEY_D && check_space(data->map, data->p_x + 1, data->p_y, data))
	{
		move_player(data, data->p_x + 1, data->p_y);
	}
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return(0);
}
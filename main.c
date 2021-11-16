/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:19:03 by knoda             #+#    #+#             */
/*   Updated: 2021/11/16 21:01:27 by knoda            ###   ########.fr       */
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

void	*xpm_to_img(char *path, t_mlx_data data)
{
	int	img_width;
	int	img_height;
	
	return (mlx_xpm_file_to_image(data.mlx, path, &img_width, &img_height));
}

void	*get_img(char c, t_mlx_data data)
{
	void	*img;
	
	img = NULL;
	if (c == '1')
		img = xpm_to_img("./srcs/bush.xpm", data);
	else if (c == 'E')
		img = xpm_to_img("./srcs/exit.xpm", data);
	else if (c == 'C')
		img = xpm_to_img("./srcs/treasure.xpm", data);
	else if (c == 'P')
		img = xpm_to_img("./srcs/player.xpm", data);
	else
	{
		exit_error("get_img: no character support");
	}
	return (img);
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

int	key_hook(int keycode, t_mlx_data *data)
{
	t_map	m;

	m = data->map;

	printf("keycode = %d\n", keycode);
	if (keycode == KEY_W && check_space(data->map, data->p_x, data->p_y - 1))
	{
		printf("move up\n");
	}
	if (keycode == KEY_A && check_space(data->map, data->p_x - 1, data->p_y))
	{
		printf("move left\n");
	}
	if (keycode == KEY_S && check_space(data->map, data->p_x, data->p_y + 1))
	{
		printf("move down\n");
	}
	if (keycode == KEY_D && check_space(data->map, data->p_x + 1, data->p_y))
	{
		printf("move right\n");
	}
	// (void)data;
	return(0);
}

int	exit_program(int keycode, t_mlx_data *data)
{
	(void)data;
	exit(0);
	return (keycode);
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
	mlx_hook(data.win, 17, 1L<<17, exit_program, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}

int     main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit_error("enter the .ber file path\n");
	parse(argv[1], &map);
	// print_map(map);
	put_backgroud(map);
	exit(0);
	return (0);
}
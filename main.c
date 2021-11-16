/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:19:03 by knoda             #+#    #+#             */
/*   Updated: 2021/11/16 16:40:32 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_backgroud(t_map map)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*bg_path = "./srcs/ground.xpm";
	int		img_width;
	int		img_height;
	int		res_x;
	int		res_y;
	int		x;
	int		y;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, bg_path, &img_width, &img_height);
	if (!img)
		exit_error("no image found");
	res_x =  map.w * IMG_PIXELS;
	res_y = map.h * IMG_PIXELS;

	mlx_win = mlx_new_window(mlx, res_x, res_y, "Game Screen");
	y = 0;
	while (y < map.h)
	{
		x = 0;
		while (x < map.w)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, IMG_PIXELS * x, IMG_PIXELS * y);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
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
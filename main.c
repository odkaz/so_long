/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:19:03 by knoda             #+#    #+#             */
/*   Updated: 2021/11/15 15:41:25 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_img()
{
	
	// void	*img;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	put_img()
{
	void	*mlx;
	void	*img;
	void	*img2;
	void	*mlx_win;
	char	*relative_path = "./srcs/adventurer-run3-01.xpm";
	char	*relative_path2 = "./srcs/smallgrass.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	if (!img)
		exit_error("no image found");
	mlx_win = mlx_new_window(mlx, 640, 480, "Game Screen");
	mlx_put_image_to_window(mlx, mlx_win, img2, 100, 100);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	mlx_loop(mlx);
}

int     main(int argc, char **argv)
{
	char    **map;
	
	if (argc != 2)
		exit_error("enter the .ber file path\n");
	map = parse(argv[1]);
	print_map(map);
	// draw_img();
	put_img();
	exit(0);
	return (0);
}
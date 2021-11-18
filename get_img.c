/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:31:09 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 17:06:57 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_to_img(char *path, t_mlx_data data)
{
	int	img_width;
	int	img_height;
    void   *img;

    img = mlx_xpm_file_to_image(data.mlx, path, &img_width, &img_height);
    if (!img)
        exit_error("xpm_to_img : img not found");
	return (img);
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
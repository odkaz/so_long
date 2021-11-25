/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:27:38 by knoda             #+#    #+#             */
/*   Updated: 2021/11/25 14:00:32 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->h)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	exit_error(char *msg, t_map *map)
{
	int		i;

	if (map)
	{
		i = 0;
		while (i < map->h)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

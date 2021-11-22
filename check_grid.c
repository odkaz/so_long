/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:58:36 by knoda             #+#    #+#             */
/*   Updated: 2021/11/22 18:35:21 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h)
	{
		if (y == 0 || y == map->h - 1)
		{
			x = 0;
			while (x < map->w)
			{
				if (map->grid[y][x] != '1')
					exit_error("maps : the map should be surrounded by walls", map);
				x++;
			}
		}
		else if (map->grid[y][0] != '1' || map->grid[y][map->w - 1] != '1')
			exit_error("maps : the map should be surrounded by walls", map);
		y++;
	}
}

void	check_flags(int p, int c, int e, t_map *map)
{
	if (p == 0)
		exit_error("maps : you have to declare the starting posisiton", map);
	if (p > 1)
		exit_error("maps : you can only have one starting point", map);
	if (c == 0)
		exit_error("maps : you need at least one collective", map);
	if (e == 0)
		exit_error("maps : you need at least one exit", map);
}

void	count_flags(t_flag *flag, char c, t_map *map)
{
	if (!ft_strchr("01PCE", c))
		exit_error("maps : invalid character", map);
	if (c == 'P')
		(flag->p)++;
	if (c == 'C')
		(flag->c)++;
	if (c == 'E')
		(flag->e)++;
}

void	check_grid(t_map *map)
{
	int		x;
	int		y;
	t_flag	flag;

	flag.p = 0;
	flag.c = 0;
	flag.e = 0;
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			count_flags(&flag, map->grid[y][x], map);
			x++;
		}
		y++;
	}
	check_flags(flag.p, flag.c, flag.e, map);
}

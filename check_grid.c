/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:58:36 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 18:08:50 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_walls(t_map map)
{
	int     x;
	int     y;

	y = 0;
	while (y < map.h)
	{
		if (y == 0 || y == map.h - 1)
		{
			x = 0;
			while (x < map.w)
			{
				if (map.grid[y][x] != '1')
					exit_error("maps : the map should be surrounded by walls");
				x++;
			}
		}
		else if (map.grid[y][0] != '1' || map.grid[y][map.w - 1] != '1')
			exit_error("maps : the map should be surrounded by walls");
		y++;
	}
}

void	check_flags(int	p, int c, int e)
{
	if (p == 0)
		exit_error("maps : you have to declare the starting posisiton");
	if (p > 1)
		exit_error("maps : you can only have one starting point");
	if (c == 0)
		exit_error("maps : you need at least one collective");
	if (e == 0)
		exit_error("maps : you need at least one exit");
}

void	check_grid(t_map map)
{
	int		x;
	int		y;
	int		flag_P;
	int		flag_C;
	int		flag_E;

	flag_P = 0;
	flag_C = 0;
	flag_E = 0;
	y = 0;
	while (y < map.h)
	{
		x = 0;
		while (x < map.w)
		{
			if (map.grid[y][x] == 'P')
				flag_P++;
			if (map.grid[y][x] == 'C')
				flag_C++;
			if (map.grid[y][x] == 'E')
				flag_E++;
			x++;
		}
		y++;
	}
	check_flags(flag_P, flag_C, flag_E);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:23:56 by knoda             #+#    #+#             */
/*   Updated: 2021/11/22 19:23:52 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	print_map(t_map map)
{
	char	**grid;

	printf("w = %d\n", map.w);
	printf("h = %d\n", map.h);
	grid = map.grid;
	while (*grid)
	{
		ft_putstr_fd("line = ", 1);
		ft_putendl_fd(*grid, 1);
		grid++;
	}
}

void	*my_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void *)ft_calloc(n, size);
	if (!res)
		exit_error("malloc failed", NULL);
	return (res);
}

int	width_count(char *line)
{
	int		w;

	w = 0;
	while (line[w])
	{
		if (line[w] == '\n')
			break ;
		w++;
	}
	return (w);
}

int	height_count(char *line)
{
	int		w;
	int		h;

	h = 0;
	if (*line)
		w = width_count(line);
	else
		exit_error("map is invalid", NULL);
	while (*line)
	{
		if (*line == '\n')
			line++;
		if (w != width_count(line))
			exit_error("the map should be rectangular", NULL);
		if (w)
		{
			line += w;
			h++;
		}
	}
	return (h);
}

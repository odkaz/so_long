/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:22:16 by knoda             #+#    #+#             */
/*   Updated: 2021/11/22 18:22:43 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*parse(char *path, t_map *map)
{
	char	*line;

	line = read_all(path);
	(*map).w = width_count(line);
	(*map).h = height_count(line);
	set_grid(map, line);
	free(line);
	check_grid(map);
	check_walls(map);
	return (map);
}

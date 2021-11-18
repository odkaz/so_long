/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:36:03 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 17:36:43 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_grid(t_map *m, char *line)
{
	char	*p;
	int		i;

	m->grid = (char **)my_calloc(m->h + 1, sizeof(char *));
	p = line;
	i = 0;
	while (*p)
	{
		if (*p == '\n')
		{
			m->grid[i] = ft_substr(line, 0, p - line);
			i++;
			line = p + 1;
		}
		p++;
	}
	if (p - line > 0)
	{
		m->grid[i] = ft_substr(line, 0, p - line);
		i++;
	}
	m->grid[i] = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:23:56 by knoda             #+#    #+#             */
/*   Updated: 2021/11/14 14:57:11 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	print_map(char **map)
{
	while (*map)
	{
        ft_putstr_fd("line = ", 1);
		ft_putendl_fd(*map, 1);
		map++;
	}
}

void	*my_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void	*)ft_calloc(n , size);
	if (!res)
		exit_error("malloc failed");
	return (res);
}
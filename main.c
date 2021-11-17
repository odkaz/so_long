/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:19:03 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 14:34:12 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
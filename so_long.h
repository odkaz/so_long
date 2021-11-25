/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:33:05 by knoda             #+#    #+#             */
/*   Updated: 2021/11/25 12:50:16 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# include "minilibx_opengl_20191021/mlx_png.h"

typedef struct s_map {
	char	**grid;
	int		w;
	int		h;
	int		c_num;
}				t_map;

typedef struct s_flag {
	int		p;
	int		c;
	int		e;
}				t_flag;

typedef struct s_mlx_data {
	void		*mlx;
	void		*win;
	void		*img;
	t_map		*map;
	int			p_x;
	int			p_y;
	int			collective;
	int			moves;
}				t_mlx_data;

void	free_grid(t_map *map);
void	exit_error(char *msg, t_map *map);
void	print_map(t_map map);
int		width_count(char *line);
int		height_count(char *line);
void	*my_calloc(size_t n, size_t size);
t_map	*parse(char *path, t_map *map);
void	put_backgroud(t_map *map);
void	*xpm_to_img(char *path, t_mlx_data data);
void	*get_img(char c, t_mlx_data data);
char	*get_img_path(char c);
int		exit_hook(int keycode, t_mlx_data *data);
int		key_hook(int keycode, t_mlx_data *data);
void	check_walls(t_map *map);
void	check_grid(t_map *map);
char	*read_all(char *path);
void	set_grid(t_map *m, char *line);

# define BUFFER_SIZE 1024
# define IMG_PIXELS 32
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

#endif
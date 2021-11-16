#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "minilibx_opengl_20191021/mlx_png.h"


typedef struct	s_mlx_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			img_width;
	int			img_height;
}				t_mlx_data;

typedef struct	s_map {
	char	**grid;
	int		w;
	int		h;
}				t_map;



void	exit_error(char *msg);
void	print_map(t_map map);
void	*my_calloc(size_t n, size_t size);
t_map	*parse(char *path, t_map *map);

#define BUFFER_SIZE 1024
#define IMG_PIXELS 32

#endif
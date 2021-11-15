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


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
	char	**map;
	int		w;
	int		h;
}				t_map;

void	exit_error(char *msg);
void	print_map(char **map);
void	*my_calloc(size_t n, size_t size);
char	**parse(char *path);

#define BUFFER_SIZE 1024

#endif
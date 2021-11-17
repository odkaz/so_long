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

typedef struct	s_map {
	char	**grid;
	int		w;
	int		h;
}				t_map;

typedef struct	s_mlx_data {
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	int			p_x;
	int			p_y;
}				t_mlx_data;



void	exit_error(char *msg);
void	print_map(t_map map);
void	*my_calloc(size_t n, size_t size);
t_map	*parse(char *path, t_map *map);
void	put_backgroud(t_map map);
void	*xpm_to_img(char *path, t_mlx_data data);
void	*get_img(char c, t_mlx_data data);
int		exit_hook(int keycode, t_mlx_data *data);
int		key_hook(int keycode, t_mlx_data *data);


#define BUFFER_SIZE 1024
#define IMG_PIXELS 32
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

#endif
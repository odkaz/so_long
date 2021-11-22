# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoda <knoda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 18:37:49 by knoda             #+#    #+#              #
#    Updated: 2021/11/22 18:57:40 by knoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := -L. -lmlx -framework OpenGL -framework AppKit -lft
SRCS := main.c parse.c util.c put_background.c get_img.c hook.c check_grid.c read_all.c set_grid.c
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx_opengl_20191021
	cp ./libft/libft.a .
	cp ./minilibx_opengl_20191021/libmlx.a .
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_opengl_20191021
	$(RM) $(OBJS) libft.a libmlx.a
	
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
re: fclean all

init:
	git submodule init
	git submodule update

.PHONY: all clean fclean re .c.o
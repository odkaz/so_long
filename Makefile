# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoda <knoda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 18:37:49 by knoda             #+#    #+#              #
#    Updated: 2021/11/17 17:59:27 by knoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := -L. -lmlx -framework OpenGL -framework AppKit -lft
SRCS := main.c parse.c util.c put_background.c get_img.c hook.c check_grid.c
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
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) libft.a libmlx.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
re: fclean all
.PHONY: all clean fclean re .c.o
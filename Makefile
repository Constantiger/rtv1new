# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aannara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 10:40:08 by aannara           #+#    #+#              #
#    Updated: 2019/11/23 12:27:50 by aannara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c loop.c vec.c ray.c color.c sphere.c cylinder.c plane.c cone.c

MLX_FLAGS = -I minilibx -lmlx -framework OpenGL -framework AppKit

NAME = RTv1

all:
	gcc -o $(NAME) $(SRC) $(MLX_FLAGS) -O3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aannara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 10:40:08 by aannara           #+#    #+#              #
#    Updated: 2019/11/25 17:52:13 by aannara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/main.c ./src/loop.c ./src/vec.c ./src/ray.c ./src/color.c \
	./src/sphere.c ./src/cylinder.c ./src/plane.c ./src/cone.c \
	./src/rotate_cam.c ./src/keys.c ./src/cone_norm.c ./src/cylinder_norm.c \
	./src/sphere_norm.c ./src/set.c ./src/vec_math.c ./src/draw.c \
	./src/render.c ./src/push.c ./src/figure.c ./src/figure_helper.c \
	./src/print_err.c ./src/read.c ./src/read_helper.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -O3

MLX_FLAGS = -I minilibx -lmlx -framework OpenGL -framework AppKit

INC = ./inc

MLX = ./mlx/libmlx.a

NAME = RTv1

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(HEADERS)
	gcc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) $(MLX)

.c.o: $(HEADERS)
	gcc -I$(INC) $(FLAGS) -c $< -o $@

$(MLX):
	make -C ./mlx/

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	make clean -C ./mlx/
	/bin/rm -f $(NAME)

re: fclean all

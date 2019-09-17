# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 22:00:39 by akoropet          #+#    #+#              #
#    Updated: 2019/09/17 19:44:11 by akoropet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol

SRC_DIR = 	./source/
OBJ_DIR = 	./objective/
INC_DIR = 	./include/

SRC = 		main.c				\
			mandelbrot.c		\
			julia.c				\
			ft_hook_key.c		\
			burning_ship.c		\
			fish.c				\
			dipper.c			\
			bird.c				\
			flying_squirrel.c	\
			elvis.c				\
			ft_thread.c			\
			ft_info.c

LIB = 		./lib/lib.a

OBJ = 		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Werror -Wextra -pthread

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib
	@make -C minilibx_macos
	@gcc $(FLAGS) $(MLX_FLAGS) $(addprefix $(SRC_DIR), $(SRC)) $(LIB) -o $(NAME)
	@echo "\033[92m>>>fractol compiled<<<\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make clean -C lib
	@make clean -C minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib
	@make clean -C minilibx_macos
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

mlx:
	man /usr/share/man/man3/mlx.1

loop:
	man /usr/share/man/man3/mlx_loop.1

image:
	man /usr/share/man/man3/mlx_new_image.1

window:
	man /usr/share/man/man3/mlx_new_window.1

pixel:
	man /usr/share/man/man3/mlx_pixel_put.1

vpath %.c $(SRC_DIR)

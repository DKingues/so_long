# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 18:57:12 by dicosta-          #+#    #+#              #
#    Updated: 2025/04/09 18:21:29 by dicosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files

NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror -g

FT_PRINTF = cd ft_printf && make

MLX_DIR =  cd minilibx-linux && make

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

PRINTF = ft_printf/libftprintf.a

MLX = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCS = srcs/map_parsing.c srcs/main.c srcs/map_parsing_aux.c srcs/map_access.c \
		srcs/draw_image.c srcs/game.c srcs/keys.c

# Sources and Objects

OBJS = $(SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
# Messages

COMP_START = echo "\nCompilation starting...\n"

GAME_READY = echo "\n The game is ready...\n"

CLEAN_DONE = echo "\nDeleted objects\n"

FCLEAN_DONE = echo "\nDeleted objects and executables\n"

all: $(NAME)

$(NAME): $(OBJS) comp_start so_long

comp_start:
	$(COMP_START)
	$(FT_PRINTF)
	$(MLX_DIR)

so_long: $(SRCS)
	$(CC) $(FLAGS) $(OBJS) $(PRINTF) $(MLX) $(GNL) -o $(NAME)
	$(GAME_READY)

clean:
	rm -rf $(OBJS)
	cd ft_printf && make clean
	cd minilibx-linux && make clean

fclean: clean
	rm -rf $(NAME)
	cd ft_printf && make fclean

re: fclean all

.PHONY: all so_long comp_start clean fclean re


run:so_long
	./so_long maps/heart.ber
	./so_long maps/floodFillTest.ber
	./so_long maps/map1.ber
	./so_long maps/empty_map_file.ber





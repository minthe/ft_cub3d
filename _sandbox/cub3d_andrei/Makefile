# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:30:15 by aionescu          #+#    #+#              #
#    Updated: 2022/11/17 19:08:15 by lorfanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC		=	main.c \
			extra_checks.c \
			file_structure_check.c \
			final_map.c \
			handle_game_exit.c \
			init_and_render_img.c \
			keyboard.c \
			keyboard_utils.c \
			layout_logic_check.c \
			missing_info_check.c \
			parsing_utils.c \
			process_gamedata.c \
			process_nsew.c \
			process_floor_ceiling.c \
			process_layout.c \
			player_movement.c \
			parse_and_report.c \
			render_floor_ceiling.c \
			raycast.c \
		
CC		=	gcc
CFLAGS_LINUX= -Wall -Wextra -Werror mlx/libmlx.a -lXext -lX11 -lm -lz -o
CFLAGS_MAC= -Wall -Wextra -Werror mlx/libmlx.a /usr/X11/lib/libXext.dylib /usr/X11/lib/libX11.dylib -lm -lz -o

LIBFT_DIR = libft/
LIBFT = libft/libft.a

MINILBX_DIR = ./mlx

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
CFLAGS= $(CFLAGS_MAC)
else
CFLAGS= $(CFLAGS_LINUX)
endif

$(NAME):
	$(MAKE) all -C $(LIBFT_DIR)
	$(MAKE) all -C $(MINILBX_DIR)
	$(CC) $(SRC) $(LIBFT) $(CFLAGS) $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C $(MINILBX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
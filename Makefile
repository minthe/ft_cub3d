# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:46:38 by vfuhlenb          #+#    #+#              #
#    Updated: 2023/01/27 22:39:11 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/sh

NAME =	cub3D

OBJECTS = $(subst .c,.o,$(SOURCES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MINILIBX_DIR	= src/inc/mlx
LIBFT_DIR		= src/inc/libft
X11_INC			= /usr/X11/include
X11_LIB			= /usr/X11/lib

LFLAGS 			= -L${LIBFT_DIR} -L${MINILIBX_DIR} -L${X11_LIB} -lmlx -lXext -lX11 -lft -lm

IDIR			= .
IFLAGS			= -I${IDIR} -I${LIBFT_DIR} -I${MINILIBX_DIR} -I${X11_INC}

SRCS = src/main.c \
		src/inc/get_next_line/get_next_line.c\
		src/inc/get_next_line/get_next_line_utils.c\
		src/import_cub.c\
		src/import_cub2.c\
		src/import_map.c\
		src/init_struct.c\
		src/check_cub.c\
		src/check_map.c\
		src/check_elements.c\
		src/cleanup.c\
		src/list_utils.c\
		src/import_color.c\
		src/atoi_cub.c\
		src/utils/map_utils.c\
		src/utils/error_msg_exit.c\
		src/utils/ft_open_file.c\
		src/utils/ft_check_fileext.c\
		src/utils/ft_whitespace.c\
		src/utils/ft_strdup_cub.c\
		src/utils/ft_free_doublepoint.c\
		src/utils/peeks.c\
		src/wall_textures.c\
		src/exec.c\
		src/keys.c\
		src/keys_2.c\
		src/map_plr_utils.c\
		src/ray.c\
		src/ray2.c\

RM = rm -f

${NAME} : ${SRCS}
		@make -C ${LIBFT_DIR}
		@make -C ${MINILIBX_DIR}
		${CC} ${CFLAGS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}

all: ${NAME}

clean:
		@${RM} ${NAME}
		@make clean -C ${LIBFT_DIR}
		@make clean -C ${MINILIBX_DIR}

fclean: clean
		@make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re

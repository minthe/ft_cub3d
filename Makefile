# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:46:38 by vfuhlenb          #+#    #+#              #
#    Updated: 2023/01/14 17:48:48 by vfuhlenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = /usr/X11/lib/libXext.dylib /usr/X11/lib/libX11.dylib -lm -lz
MLX = inc/mlx/libmlx.a

RM = rm -f
AF = ar rcs

SRCS = \
inc/get_next_line/get_next_line.c\
inc/get_next_line/get_next_line_utils.c\
src/import_cub.c\
src/import_map.c\
src/init_struct.c\
src/check_cub.c\
src/check_map.c\
src/check_elements.c\
src/cleanup.c\
src/list_utils.c\
src/import_color.c\
src/atoi_cub.c\
utils/map_utils.c\
utils/error_msg_exit.c\
utils/ft_open_file.c\
utils/ft_check_fileext.c\
utils/ft_whitespace.c\
utils/ft_strdup_cub.c\
utils/ft_free_doublepoint.c\
utils/peeks.c\
cub3d.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C inc/libft
	make bonus -C inc/libft
	make -C inc/mlx
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C inc/libft
	make clean -C inc/mlx

fclean: clean
	$(RM) $(NAME)
	make fclean -C inc/libft

re: fclean all

norminette:
	norminette $(SRCS)
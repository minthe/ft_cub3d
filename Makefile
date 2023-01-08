# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:46:38 by vfuhlenb          #+#    #+#              #
#    Updated: 2023/01/08 21:24:18 by vfuhlenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = -L/usr/X11/include -L/usr/X11/lib -lXext -lX11 -lm -lz

RM = rm -f
AF = ar rcs

SRCS = \
inc/get_next_line/get_next_line.c\
inc/get_next_line/get_next_line_utils.c\
src/import_cub.c\
src/init_struct.c\
src/check_cub.c\
src/check_map.c\
src/err_cub.c\
src/cleanup.c\
src/list_utils.c\
src/import_color.c\
src/atoi_cub.c\
utils/ft_open_file.c\
utils/ft_check_fileext.c\
utils/ft_whitespace.c\
utils/ft_strdup_cub.c\
utils/ft_free_doublepoint.c\
cub3d.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C inc/libft
	make bonus -C inc/libft
	make -C inc/mlx
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = inc/mlx/libmlx.a
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
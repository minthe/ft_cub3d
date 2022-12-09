# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:46:38 by vfuhlenb          #+#    #+#              #
#    Updated: 2022/12/08 15:54:55 by vfuhlenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = -lXext -lX11 -lm -lz

RM = rm -f
AF = ar rcs

SRCS = \
inc/get_next_line/get_next_line.c\
inc/get_next_line/get_next_line_utils.c\
src/import_cub.c\
src/init_struct.c\
src/check_cub.c\
src/err_elements.c\
utils/ft_open_file.c\
utils/ft_check_fileext.c\
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

fclean: clean
	$(RM) $(NAME)
	make fclean -C inc/libft

re: fclean all

norminette:
	norminette $(SRCS)
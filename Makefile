# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:46:38 by vfuhlenb          #+#    #+#              #
#    Updated: 2022/12/08 14:41:43 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = -lXext -lX11 -lm -lz

RM = rm -f
AF = ar rcs

SRCS = \
keys.c\
mytake.c\


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
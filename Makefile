# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:46:38 by vfuhlenb          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/01/14 19:46:40 by vfuhlenb         ###   ########.fr        #
=======
#    Updated: 2023/01/13 12:50:11 by dimbrea          ###   ########.fr        #
>>>>>>> dimbrea
#                                                                              #
# **************************************************************************** #

NAME = cub3d

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
CFLAGS= $(CFLAGS_MAC)
else
CFLAGS= $(CFLAGS_LINUX)
endif

UNAME = $(shell uname)
CC = gcc
<<<<<<< HEAD
CFLAGS_LINUX= -Wall -Wextra -Werror inc/mlx/libmlx_$(UNAME).a -lXext -lX11 -lm -lz -fsanitize=address -g
CFLAGS_MAC= -Wall -Wextra -Werror  -fsanitize=address -g
=======
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = -lXext -lX11 -lm -lz
>>>>>>> dimbrea

RM = rm -f
AF = ar rcs

SRCS = \
<<<<<<< HEAD
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
=======
keys.c\
ray.c\
main.c\

>>>>>>> dimbrea

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C inc/mlx/
	make -C inc/libft/
	make bonus -C inc/libft/
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

clean:
	$(RM) $(OBJS)
<<<<<<< HEAD
	make clean -C inc/libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C inc/libft/
=======
	make clean -C inc/libft
	make clean -C inc/mlx

fclean: clean
	$(RM) $(NAME)
	make fclean -C inc/libft
	make clean -C inc/mlx
>>>>>>> dimbrea

re: fclean all

norminette:
	norminette $(SRCS)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 15:11:30 by vfuhlenb          #+#    #+#              #
#    Updated: 2021/12/20 14:41:32 by vfuhlenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRCS= ft_printf.c conversions.c
OBJS=${SRCS:.c=.o}
RM = rm -rf
OPTION = -c

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	${RM} */*.o

fclean: clean
	${RM} $(NAME)
	${RM} libft/libft.a

re: fclean all

.PHONY:	all clean fclean re

SRCS	=	ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c\
			ft_isprint.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_memmove.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strlcpy.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_atoi.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_itoa.c \
			ft_split.c \

SRCS_B	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \

OBJS			=	${SRCS:.c=.o}
OBJS_B			=	${SRCS_B:.c=.o}
HEADER_FILES	=	libft.h
NAME			=	libft.a
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -g

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(OBJS) $(OBJS_B)
				ar rcs $(NAME) $(OBJS) $(OBJS_B)

%.o:			%.c	$(HEADER_FILES)
				$(CC) -c $(CFLAGS) -o $@ $<

clean:
				$(RM) $(OBJS)

cleanb:
				$(RM) $(OBJS) $(OBJS_B)

fclean:			cleanb
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all %.o clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msorin <msorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/06 16:09:33 by msorin            #+#    #+#              #
#    Updated: 2017/12/08 12:52:10 by msorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRC =	ft_atoi.c ft_bzero.c ft_getenv.c ft_initstr.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c \
	ft_lstcpy.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_minmax.c ft_nblen.c ft_putchar.c \
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_putnbrendl.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoin_f.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnequ.c ft_strndup.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strsplit_last.c ft_strstr.c ft_strsub.c \
	ft_strtrim.c ft_tolower.c ft_toupper.c

CFLAGS =	-Wall -Werror -Wextra -I .

CC =		gcc $(CFLAGS)

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
			$(CC) -c $(CFLAGS) $(SRC)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

norme:
	norminette $(SRC) libft.h

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

compile: re
	$(MAKE) fclean

.PHONY:		all norme clean fclean re compile

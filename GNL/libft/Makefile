# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:14:54 by abungert          #+#    #+#              #
#    Updated: 2015/12/30 13:18:07 by abungert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c \
	ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
 	ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memdel.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	ft_strrchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strstr.c ft_tolower.c ft_toupper.c \
	ft_strdel.c ft_strtrim.c ft_strsub.c ft_strsplit.c ft_strclr.c ft_strequ.c ft_striter.c \
	ft_striter.c ft_strmap.c ft_striteri.c ft_strmapi.c ft_strnequ.c ft_power.c ft_strrev.c \
	ft_lstiter.c ft_lstadd.c ft_lstmap.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_strplc.c ft_strrplc.c ft_strndup.c

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -I./includes
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)


re: fclean all

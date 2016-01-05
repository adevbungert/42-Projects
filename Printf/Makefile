# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/05 14:22:12 by abungert          #+#    #+#              #
#    Updated: 2016/01/05 16:47:47 by abungert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=ft_printf.c ft_putchar.c ft_putstr.c ft_itoa.c

OBJ=$(SRC:.c=.o)
CC=gcc
ifdef FLAGS
    ifeq ($(FLAGS), no)
        CFLAGS=-c
    endif
    ifeq ($(FLAGS), debug)
        CFLAGS= -c -Wall -Wextra -Werror -ansi -pedantic -g
    endif
else
    CFLAGS      = -c -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)


re: fclean all
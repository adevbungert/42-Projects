# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperrin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 11:03:32 by jperrin           #+#    #+#              #
#    Updated: 2015/12/18 13:05:52 by jperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = ./src

SRC = ft_isalnum.c \
	  ft_atoi.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_memset.c \
	ft_memmove.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_bzero.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strlcat.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncpy.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strnew.c \
	ft_memdel.c \
	ft_strdel.c \
	ft_memalloc.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_lstnew.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstpb.c \
	ft_countchar.c \
	ft_countword.c \
	ft_swapbit.c \
	ft_countcharinstr.c \
	ft_lstdup.c \
	ft_poplist.c \

OBJ = $(SRC:.c=.o)

OBJDIR = ./binaries

INCLUDES = ./includes

FLAGS = -Wall -Werror -Wextra

CREATE_LIB = ar -rc $(NAME) $(OBJ)

RANLIB = ranlib $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I $(INCLUDES)
	$(CREATE_LIB)
	$(RANLIB)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

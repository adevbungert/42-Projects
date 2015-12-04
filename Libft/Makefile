# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:14:54 by abungert          #+#    #+#              #
#    Updated: 2015/12/03 15:28:58 by abungert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DBPATH=db_
REPATH=ft_

CURPATH=$(DBPATH)
#CURPATH=$(REPATH)

NAME=libft.a

SRCLIST=ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl \
	ft_isdigit ft_isgraph ft_islower ft_isprint ft_ispunct ft_isspace ft_isupper \
 	ft_itoa ft_memalloc ft_memccpy ft_memchr ft_memdel \
	ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl \
	ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr \
	ft_strrchr ft_strcmp ft_strcpy ft_strdup ft_strjoin ft_strlcat ft_strlen ft_strncat \
	ft_strncmp ft_strncpy ft_strnew ft_strnstr ft_strstr ft_tolower ft_toupper \
	ft_strdel ft_strtrim ft_strsub ft_strsplit ft_strclr ft_strequ ft_striter \
	ft_striter ft_strmap ft_striteri ft_strmapi ft_strnequ ft_power ft_strrev \
	ft_lstiter ft_lstadd ft_lstmap ft_lstnew ft_lstdelone ft_lstdel \
	ft_strplc ft_strrplc

HDRLIST=libft

SRCPATH=./

HDRPATH=./

CCHPATH=cache/

SRC=$(addprefix $(SRCPATH),$(addsuffix .c,$(SRCLIST)))
OBJ=$(addprefix $(CCHPATH),$(addsuffix .o,$(SRCLIST)))
HDR=$(addprefix $(HDRPATH),$(addsuffix .h,$(HDRLIST)))
CC=clang
CFLAGS=-Wall -Wextra
FULCFLAGS=$(CFLAGS) -I $(HDRPATH)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHPATH)
	$(CC) $(FULCFLAGS) -c $< -o $@


$(CCHPATH)%.h.gch: $(HDRPATH)%.h $(CCHPATH)
	$(CC) $(CFLAGS) -o $@ -c $<


$(CCHPATH):
	mkdir $(CCHPATH)


clean:
	rm -vrf $(CCHPATH)

fclean: clean
	rm -f $(NAME)


re:	fclean all


.PHONY: all clean fclean re test

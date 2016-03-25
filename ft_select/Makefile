# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebungert <antoinebungert@student.42.fr>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/21 15:48:44 by abungert          #+#    #+#              #
#    Updated: 2016/03/24 16:31:40 by abungert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FILES = main.c \
		lst_manip.c \
		term.c \
		utils.c \
		get_key.c \
		put_key.c \
		signals.c \
		window_size.c \
		print.c

SRC = $(addprefix srcs/, $(FILES))
OBJ = $(SRC:.c=.o)

FT_PRINTF = ./ft_printf

INC = -I$(FT_PRINTF)/includes -I.

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INC)

LIBS = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) -ltermcap
	@echo "\033[1;32m$@ COMPILED ✓\033[0m"

 %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Building: \033[34m$@\033[0m"

clean:
	@rm -f $(OBJ)
	@make -C $(FT_PRINTF) clean
	@echo "\033[1;31mCLEANED ✓\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean

re: fclean all

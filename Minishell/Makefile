# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 14:12:45 by abungert          #+#    #+#              #
#    Updated: 2016/02/10 15:38:12 by abungert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$(HEADERS)

FILES		= main.c \
			  commands.c \
			  env_variables.c \
			  builtins.c \
			  signals.c

LIBFT		= ./libft

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

HEADERS		= .

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

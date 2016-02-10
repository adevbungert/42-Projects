# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 15:32:25 by abungert          #+#    #+#              #
#    Updated: 2016/02/01 11:56:32 by abungert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.

FILES	= main.c \
		  parse_arguments.c \
		  browse_directory.c \
		  get_file_info.c \
		  print_files.c print_files_bis.c \
		  print_utils.c \
		  errors.c \
		  manage_lists.c \
		  free.c \
		  sort_files.c

LIBFT	= ./libft

SRC		= $(addprefix srcs/, $(FILES))
OBJ		= $(SRC:.c=.o)

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

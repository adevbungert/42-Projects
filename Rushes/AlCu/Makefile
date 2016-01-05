# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperrin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 11:51:01 by jperrin           #+#    #+#              #
#    Updated: 2015/12/21 11:21:07 by jperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = main.c lst_manip.c get_params.c check_str.c algo.c get_next_line.c

OBJ = $(SRC:.c=.o)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC) -I ./includes
	make -C ./libft	
	gcc -Wall -Werror -Wextra $(OBJ) -I ./includes -L./libft/ -lft -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

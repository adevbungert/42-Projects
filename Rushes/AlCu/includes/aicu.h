/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:48:44 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/20 14:07:51 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H
# include "get_next_line.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_lst
{
	int				nb;
	struct s_lst	*next;
}				t_lst;

int				algo(int line, int total);
int				check_str(char *str);
int				read_file(char *file, t_lst **begin);
int				read_standard_input(t_lst **begin);
t_lst			*get_last_line(t_lst **begin);
int				count_all_matches(t_lst *begin);
t_lst			*lst_pushback(t_lst **lst, t_lst *new);
t_lst			*create_list_elem(int nb);
int				add_to_list(int nb, t_lst **begin);
void			aff_map(t_lst *begin);
int				user_play(t_lst *cur_line);
int				computer_play(int line_nb, int allnb);
int				start_playing(t_lst **begin);
int 			free_list(t_lst **begin);
int				main(int ac, char **av);

#endif

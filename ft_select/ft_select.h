/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebungert <antoinebungert@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:15:12 by abungert          #+#    #+#             */
/*   Updated: 2016/03/23 11:11:51 by antoinebungert   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "ft_printf.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <signal.h>

typedef struct		s_lst
{
	char			*value;
	int				selected;
	int				len;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_select
{
	struct termios	term;
	int				curs_y;
	t_lst			*list;
	int				size_list;
	int				win_col;
	int				win_row;
	int				col_n;
}					t_select;

int					ft_select(int ac, char **av, t_select *params);
int					see_key();
t_select			*init_list(int ac, char **av, t_select *params);
void				print_lst(t_select *params);
int					init_term(t_select *params);
int					restore_term(t_select *params);
t_select			*save_term(t_select *params, int i);
void				fputs(char *res);
int					get_key(t_select *params);
void				fputs(char *res);
void				fmove(t_select *params);
void				print_with_effect(t_select *params, t_lst *elem);
void				press_arrow(t_select *params, char key);
void				press_enter(t_select *params);
void				press_space(t_select *params);
t_lst				*get_current_elem(t_select *params);
void				return_selected(t_select *params);
void				free_lst(t_select **params);
void				ft_signal(void);
void				sighandler(int signum);
void				press_delete(t_select *params);
int					ft_check_size(t_select *params);
void				ft_get_col_n(t_select *params);
void				ft_resize(void);
void				handle_inter();

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:15:12 by abungert          #+#    #+#             */
/*   Updated: 2016/03/22 13:41:11 by abungert         ###   ########.fr       */
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
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_select
{
	int				curs_y;
	t_lst			*list;
	int				size_list;
}					t_select;

int					see_key();
t_select			*init_list(int ac, char **av);
void				print_lst(t_select *params);
int					init_term(void);
int					restore_term(void);
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:15:12 by abungert          #+#    #+#             */
/*   Updated: 2016/03/16 15:46:42 by abungert         ###   ########.fr       */
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
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

int			see_key();

#endif

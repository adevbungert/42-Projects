/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:06:38 by abungert          #+#    #+#             */
/*   Updated: 2016/03/24 15:52:34 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

static void			handle_stop(void)
{
	t_select		*params;
	char			cp[2];

	params = NULL;
	params = save_term(params, 1);
	cp[0] = params->term.c_cc[VSUSP];
	cp[1] = 0;
	params->term.c_lflag |= ICANON;
	params->term.c_lflag |= ECHO;
	signal(SIGTSTP, SIG_DFL);
	fputs("cl");
	tcsetattr(0, 0, &(params->term));
	fputs("te");
	fputs("ve");
	ioctl(0, TIOCSTI, cp);
}

static void			handle_cont(void)
{
	t_select		*params;

	params = NULL;
	params = save_term(params, 1);
	params->term.c_lflag &= ~ICANON;
	params->term.c_lflag &= ~ECHO;
	params->term.c_cc[VMIN] = 1;
	params->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(params->term));
	fputs("ti");
	fputs("vi");
	signal(SIGTSTP, sighandler);
	ft_resize();
	ft_check_size(params);
}

void				handle_inter(void)
{
	t_select		*params;

	params = NULL;
	params = save_term(params, 1);
	restore_term(params);
}

void				sighandler(int signum)
{
	if (signum == SIGWINCH)
		ft_resize();
	else if (signum == SIGTSTP)
		handle_stop();
	else if (signum == SIGCONT)
		handle_cont();
	else if (signum == SIGSEGV)
	{
		handle_inter();
		ft_printf("Action not supported\nExiting program...\n");
		exit(0);
	}
	else
	{
		handle_inter();
		exit(0);
	}
}

void				ft_signal(void)
{
	int				i;

	i = 1;
	while (i < 32)
	{
		signal(i, sighandler);
		i++;
	}
}

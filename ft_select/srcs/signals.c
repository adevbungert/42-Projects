/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:50:02 by abungert          #+#    #+#             */
/*   Updated: 2016/03/22 13:05:18 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

static void			handle_stop()
{
	struct termios	term;
	char			cp[2];

	tcgetattr(0, &term);
	cp[0] = term.c_cc[VSUSP];
	cp[1] = 0;
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	signal(SIGTSTP, SIG_DFL);
	fputs("cl");
	tcsetattr(0, 0, &term);
	fputs("te");
	fputs("ve");
	ioctl(0, TIOCSTI, cp);
}

static void			handle_cont()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	fputs("ti");
	fputs("vi");
	signal(SIGTSTP, sighandler);
}

void				sighandler(int signum)
{
	if (signum == SIGINT || signum == SIGQUIT || signum == SIGKILL)
	{
		restore_term();
		exit(0);
	}
	if (signum == SIGTSTP)
		handle_stop();
	if (signum == SIGCONT)
		handle_cont();
	if (signum == SIGSEGV)
	{
		restore_term();
		ft_printf("Action not supported\nExiting program...\n");
		exit(0);
	}
}

void				ft_signal(void)
{
	int 			i;

	i = 1;
	while (i < 32)
	{
		signal(i, sighandler);
		i++;
	}
}

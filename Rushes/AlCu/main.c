/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:18:57 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/21 12:39:48 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include <stdio.h>

void	aff_map(t_lst *begin)
{
	t_lst	*cur;
	int		i;

	cur = begin;
	ft_putstr("\033[1;37m\n\n");
	while (cur)
	{
		if (cur->nb)
		{
			i = 0;
			while (i < cur->nb)
			{
				ft_putchar('l');
				i++;
			}
			ft_putstr("\n\n");
		}
		cur = cur->next;
	}
	ft_putstr("\n\n\033[m");
}

int		user_play(t_lst *cur_line)
{
	int		correct;
	char	*str;
	int		max_nb;
	int		res;

	correct = 1;
	while (correct)
	{
		ft_putstr("\033[1;34m==== You can take out from 1 to ");
		if (cur_line->nb <= 3)
			ft_putnbr(max_nb = cur_line->nb);
		else if ((max_nb = 3) == 3)
			ft_putchar('3');
		ft_putstr(" matche(s)  ====\033[m\n");
		ft_putstr("\033[1;32mHow many matche(s) you'd like to take? \033[m");
		res = get_next_line(0, &str);
		if (ft_strlen(str) != 1 || (ft_atoi(str) > max_nb || ft_atoi(str) < 1))
			ft_putstr("\033[0;41mWrong choice, try again\033[m\n");
		else
			correct = 0;
	}
	res = ft_atoi(str);
	ft_memdel((void **)&str);
	return (res);
}

int		computer_play(int line_nb, int allnb)
{
	int		shot;

	shot = algo(line_nb, allnb);
	ft_putstr("\n\n\033[0;35m*********************\n");
	ft_putstr("* The IA played : ");
	ft_putnbr(shot);
	ft_putstr(" *\n*********************\033[m\n\n");
	return (shot);
}

int		start_playing(t_lst **begin)
{
	int		play;
	t_lst	*cur_line;
	int		shot;
	int		turn;

	turn = 0;
	play = 1;
	while (play)
	{
		if ((cur_line = get_last_line(begin)))
		{
			if (cur_line->nb == 0)
				return (turn);
			else if (turn == 1 &&
				((shot = computer_play(cur_line->nb, count_all_matches(*begin)))
					|| 1))
				turn = 0;
			else if (turn == 0 &&
				((shot = user_play(cur_line)) || 1))
				turn = 1;
			cur_line->nb -= shot;
			aff_map(*begin);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		res;
	t_lst	*begin;

	res = 0;
	if (ac == 2)
	{
		if (!(res = read_file(av[1], &begin)))
			ft_putstr_fd("\033[1;41mERROR\n\033[m", 2);
	}
	else if (ac == 1)
		if(!(res = read_standard_input(&begin)))
			ft_putstr_fd("\033[1;41mERROR\n\033[m", 2);
	if (res == 1)
	{
		aff_map(begin);
		if (start_playing(&begin) == 0)
			ft_putstr("\033[1;32m---> YOU WON ! <---\n\033[m");
		else
			ft_putstr("\033[1;31m---> IA WON ! <---\n\033[m");
	}
	free_list(&begin);
}

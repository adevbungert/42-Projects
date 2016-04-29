/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:15:52 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:33:27 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(int *pile, int length)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (length == 0)
		ft_putchar('_');
	while (i < length)
	{
		if (start)
			ft_putchar(' ');
		ft_putnbr(pile[i]);
		start = 1;
		i++;
	}
}

void	print_state(t_pushswap *data)
{
	if (ft_strlen(data->sequence) > 0)
		ft_printf("{red}%s{eoc}\nMoves: %d\n",
				data->sequence, data->nb_of_moves);
	ft_putstr("Pile A: ");
	ft_putstr("\033[32m");
	print_pile(data->pile_a, data->length_a);
	ft_putstr("\033[0m");
	ft_putchar('\n');
	ft_putstr("Pile B: ");
	ft_putstr("\033[33m");
	print_pile(data->pile_b, data->length_b);
	ft_putstr("\033[0m");
	ft_putstr("\n\n");
}

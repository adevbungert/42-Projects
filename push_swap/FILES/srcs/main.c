/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:08:43 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 12:50:06 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnumber(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (!ft_isdigit(value[i]) && value[i] != '-' && value[i] != '+')
			return (0);
		i++;
	}
	if (ft_strlen(value) == 1)
		if (value[0] == '-' || value[0] == '+')
			return (0);
	return (1);
}

int		check_duplicate(int nb, int *pile, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		if (pile[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		*init_piles(t_pushswap *data, char **argv, int argc)
{
	int		*pile;
	int		i;
	int		nb;

	pile = (int *)ft_memalloc(sizeof(int) * argc);
	i = 0;
	data->smallest_a = ft_atoi(argv[0]);
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		nb = ft_atoi(argv[i]);
		if (!check_duplicate(nb, pile, i))
			return (NULL);
		if (nb <= data->smallest_a)
		{
			data->smallest_a = nb;
			data->pos_smallest_a = i;
		}
		pile[i] = ft_atoi(argv[i]);
		i++;
	}
	data->pile_a = pile;
	data->length_a = i;
	return (pile);
}

int		add_options(char *options, t_pushswap *data, int *argc, char ***argv)
{
	int		i;

	if (ft_strlen(options) == 2)
		return (0);
	i = 2;
	while (options[i])
	{
		if (options[i] == 'v')
			data->verbose = 1;
		else if (options[i] == 'f')
			data->fast = 1;
		else
			return (0);
		i++;
	}
	(*argc)--;
	(*argv)++;
	return (1);
}

int		main(int argc, char **argv)
{
	t_pushswap	*data;

	if (argc == 1)
		return (0);
	data = (t_pushswap *)ft_memalloc(sizeof(t_pushswap));
	data->sequence = ft_strnew(1);
	if (ft_strncmp(argv[1], "--", 2) == 0)
	{
		if (!add_options(argv[1], data, &argc, &argv))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
	}
	if (init_piles(data, ++argv, --argc) == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	data->pile_b = (int *)ft_memalloc(sizeof(int));
	sort_pile(data);
	if (!data->fast)
		ft_printf("{red}%s{eoc}", ft_strtrim(data->sequence));
	ft_putchar('\n');
	ft_putnbr(data->nb_of_moves);
	return (0);
}

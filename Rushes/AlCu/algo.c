/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:59:03 by abungert          #+#    #+#             */
/*   Updated: 2015/12/20 14:28:30 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		algo(int line, int total)
{
	int turn;

	turn = 1;
	if ((total - line) % 4 == 0)
	{
		while (turn <= 3 && turn <= line)
		{
			if ((line - turn) % 4 == 1)
				return (turn);
			turn++;
		}
		return (turn - 1);
	}
	else
	{
		while (turn <= 3 && turn <= line)
		{
			if ((line - turn) % 4 == 0)
				return (turn);
			turn++;
		}
		return (turn - 1);
	}
}

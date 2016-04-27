/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:04:27 by abungert           #+#    #+#             */
/*   Updated: 2016/02/01 11:23:35 by abungert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_nbrlen(long nb, long base)
{
	long	length;

	length = 1;
	while (ft_power_long(base, length) <= nb)
		length++;
	return (length);
}

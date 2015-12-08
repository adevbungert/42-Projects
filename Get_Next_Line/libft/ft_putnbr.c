/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:43:56 by abungert          #+#    #+#             */
/*   Updated: 2015/11/30 17:25:28 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_bis(int n)
{
	if (n < -9 || 9 < n)
		ft_putnbr_bis(n / 10);
	ft_putchar('0' + ABS(n % 10));
}

void			ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_putnbr_bis(n);
}

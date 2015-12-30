/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:03:02 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:43:00 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_bis_fd(int n, int fd)
{
	if (n < -9 || 9 < n)
		ft_putnbr_bis_fd(n / 10, fd);
	ft_putchar_fd('0' + ABS(n % 10), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_bis_fd(n, fd);
}

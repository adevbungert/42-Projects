/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:07:31 by abungert           #+#    #+#             */
/*   Updated: 2016/02/01 11:12:14 by abungert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power_long(long nb, long pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (0);
	return (nb * ft_power(nb, pow - 1));
}

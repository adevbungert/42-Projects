/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:07:31 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:36:01 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_itoa_recursiv(char **str, int n)
{
	if (n < 0)
	{
		**str = '-';
		(*str)++;
		if (n < -1000000000)
		{
			ft_itoa_recursiv(str, -(n / 10));
			ft_itoa_recursiv(str, -(n % 10));
		}
		else
			ft_itoa_recursiv(str, -n);
	}
	if (n >= 10)
	{
		ft_itoa_recursiv(str, n / 10);
		ft_itoa_recursiv(str, n % 10);
	}
	else if (n >= 0)
	{
		**str = n + '0';
		(*str)++;
	}
}

char			*ft_itoa(int n)
{
	int		count;
	char	*str;
	char	*st;

	count = ft_countchar(n);
	if (!(str = (char *)malloc(sizeof(*str) * count + 1)))
		return (NULL);
	st = str;
	ft_itoa_recursiv(&str, n);
	*str = '\0';
	return (st);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:14:36 by abungert          #+#    #+#             */
/*   Updated: 2016/01/05 16:21:26 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int		ft_printf(const char *fmt, ...)
{
	va_list 	ap;
	char 		*s;
	char		c;
	int 		i;
	int			j;
	int			len;
	
	i = 0;
	j = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 'c' || fmt[i] == 'C')
				ft_putchar(va_arg(ap, int));
			else if (fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'D')
			{
				s = ft_itoa(va_arg(ap, int));
				ft_putstr(s);
			}
			else if (fmt[i] == 's')
				ft_putstr(va_arg(ap, char *));
			else
				return (0);
		}
		else
			ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (3);
}
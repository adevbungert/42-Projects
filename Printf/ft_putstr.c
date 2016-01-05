/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:53:35 by abungert          #+#    #+#             */
/*   Updated: 2016/01/05 15:13:25 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(const char *s)
{
	char const *str = s;

	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

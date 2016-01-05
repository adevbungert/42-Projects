/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:35:46 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:58:10 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*tmp;

	tmp = dst;
	while (*src && n > 0)
	{
		n--;
		*tmp = *src;
		tmp++;
		src++;
	}
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
	return (dst);
}

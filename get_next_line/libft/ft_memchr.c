/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:33:48 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:57:13 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*tmp;

	uc = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (n)
	{
		if (*tmp == uc)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}

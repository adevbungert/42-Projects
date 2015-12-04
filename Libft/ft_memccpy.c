/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:43:28 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:28:24 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char const		*tmp1 = src;
	unsigned char			*tmp2;

	tmp2 = dst;
	while (n-- > 0)
	{
		*tmp2 = *tmp1;
		if (*tmp2 == (unsigned char)c)
			return (tmp2 + 1);
		++tmp2;
		++tmp1;
	}
	return (NULL);
}

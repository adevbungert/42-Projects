/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:27:20 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:56:34 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	unsigned char	c_tmp;

	c_tmp = (unsigned char)c;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (n-- > 0)
	{
		*tmp1 = *tmp2;
		if (*tmp1++ == c_tmp)
			return (tmp1);
		tmp2++;
	}
	return (NULL);
}

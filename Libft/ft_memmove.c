/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:59:52 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:59:27 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_1;
	const char	*tmp_2 = (char *)src;

	tmp_1 = (char *)dst;
	if ((tmp_1 > tmp_2) && (tmp_1 < (tmp_2 + len)))
	{
		tmp_2 += len;
		tmp_1 += len;
		while (len != 0)
		{
			len--;
			tmp_1[len] = tmp_2[len];
		}
	}
	else
	{
		while (len != 0)
		{
			len--;
			*tmp_1++ = *tmp_2++;
		}
	}
	return (dst);
}

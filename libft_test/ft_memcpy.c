/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:07:06 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 18:13:15 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*tmp_1;
	unsigned char const		*tmp_2;

	tmp_1 = dst;
	tmp_2 = src;
	while (n > 0)
	{
		n--;
		*tmp_1++ = *tmp_2++;
	}
	return (dst);
}

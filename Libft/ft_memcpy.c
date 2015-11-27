/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:07:06 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:43:24 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char 	*tmp_1;
	const char 	*tmp_2 = (char *)src;;

	tmp_1 = (char *)dst;
	while (n != 0)
	{
		n--;
		*tmp_1++ = *tmp_2++;
	}
	return (dst);
}
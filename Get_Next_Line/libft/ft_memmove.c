/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:59:52 by abungert          #+#    #+#             */
/*   Updated: 2015/11/30 15:14:01 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *const str = dst;

	if (dst > src)
		while (len-- > 0)
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
	else if (dst < src)
		while (len-- > 0)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (str);
}

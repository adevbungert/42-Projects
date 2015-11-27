/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:04:08 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:54:07 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*src = s;
	unsigned char			uc;

	uc = c;
	while (n != 0)
	{
		n--;
		if (*src == uc)
			return ((void *)src);
		src++;
	}
	return NULL;
}
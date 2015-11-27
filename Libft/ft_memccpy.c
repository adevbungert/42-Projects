/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:43:28 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:53:22 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char 			*tmp_1;
	const char 		*tmp_2 = (char *)src;
	unsigned char	uc;

	tmp_1 = (char *)dst;
	uc = c;
	while (n != 0)
	{
		n--;
		*tmp_1 = *tmp_2;
		if (*tmp_2 == uc)
			break;
		tmp_1++;
		tmp_2++;
	}
	return ((*tmp_2 == uc) ? (void *)tmp_2++ : NULL);
}
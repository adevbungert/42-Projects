/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:08:20 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:43:11 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_1 = (const unsigned char *)s1;
	const unsigned char	*tmp_2 = (const unsigned char *)s2;

	while (n != 0)
	{
		n--;
		if (*tmp_1 != *tmp_2)
			return (*tmp_1 - *tmp_2);
		tmp_1++;
		tmp_2++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:44:32 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:56:12 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*tmp1;
	const char		*tmp2;
	int				i;

	tmp1 = dst;
	tmp2 = src;
	i = 0;
	while (n-- > 0)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:38:34 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 16:38:23 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*tmp1;
	const unsigned char		*tmp2;
	size_t					i;

	if (n <= 0)
		return (0);
	tmp1 = s1;
	tmp2 = s2;
	i = 0;
	while (tmp1[i] == tmp2[i] && i < (n - 1))
		i++;
	return (tmp1[i] - tmp2[i]);
}

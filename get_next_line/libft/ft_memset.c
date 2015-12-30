/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:55:34 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:21:04 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*tmp;
	int				i;

	uc = (unsigned char)c;
	tmp = b;
	i = 0;
	while (len-- > 0)
	{
		tmp[i] = uc;
		i++;
	}
	return (b);
}

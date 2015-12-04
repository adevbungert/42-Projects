/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:11:33 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:40:42 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*uc1;
	unsigned char	uc2;

	uc1 = s;
	uc2 = c;
	while (len != 0)
	{
		len--;
		*uc1++ = uc2;
	}
	return (s);
}

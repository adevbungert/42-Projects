/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:50:15 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:38:44 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dst;

	if (!s)
		return (NULL);
	i = start;
	if ((dst = (char *)malloc(sizeof(*dst) * len + 1)))
	{
		while (i < start + len)
		{
			dst[i - start] = s[i];
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}

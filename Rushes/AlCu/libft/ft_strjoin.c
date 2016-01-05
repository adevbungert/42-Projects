/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:54:04 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/17 11:54:13 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if ((dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s1)
					+ ft_strlen(s2)) + 1)))
	{
		i = -1;
		while (s1[++i])
			dst[i] = s1[i];
		while (*s2)
		{
			dst[i++] = *s2;
			s2++;
		}
		dst[i] = '\0';
		return (dst);
	}
	else
		return (NULL);
}

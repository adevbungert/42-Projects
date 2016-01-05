/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:42:58 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/17 12:05:11 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;

	count = ft_strlen((const char *)s1);
	if (!(s2 = (char*)malloc(sizeof(*s2) * (count + 1))))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:11:52 by jperrin           #+#    #+#             */
/*   Updated: 2015/11/27 15:18:31 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		temp_index;

	i = 0;
	temp_index = -1;
	while (s[i])
	{
		if (s[i] == c)
			temp_index = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	else if (temp_index != -1)
		return ((char *)s + temp_index);
	return (NULL);
}

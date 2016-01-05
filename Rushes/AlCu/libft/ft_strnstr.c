/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:13:28 by jperrin           #+#    #+#             */
/*   Updated: 2015/11/29 16:04:44 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	int				temp_i;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] && i < n)
	{
		temp_i = i;
		j = 0;
		while (s1[temp_i] == s2[j] && s2[j] && i + j < n)
		{
			temp_i++;
			j++;
		}
		if (s2[j] == '\0' || (j == n - 1 && j > 0))
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

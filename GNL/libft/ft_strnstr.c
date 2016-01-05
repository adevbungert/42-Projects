/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:40:01 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 11:51:06 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	len = ft_strlen(s2);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if ((j == len - 1) && (i + j < n))
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

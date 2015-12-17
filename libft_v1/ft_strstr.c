/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:40:35 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 11:45:53 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j == len - 1)
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:23:32 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:18:42 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**s2;
	int		i;
	int		t;
	int		j;

	if (!s || !(s2 = (char **)malloc(sizeof(*s2) * ft_countword(s, c) + 1)))
		return (NULL);
	j = -1;
	i = -1;
	t = 0;
	while (s[++i])
	{
		if ((s[i + 1] == '\0' || s[i] == c) && t != 0)
		{
			if (!(s2[++j] = (char *)malloc(sizeof(*s2) * t + 1)))
				return (NULL);
			(s[i + 1] == '\0') ? ft_strncpy(s2[j], &s[i - t], t + 1)
				: ft_strncpy(s2[j], &s[i - t], t);
			t = 0;
		}
		if (s[i] != c)
			t++;
	}
	s2[++j] = NULL;
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:59:52 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:40:34 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		size;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	j = ft_strlen(s) - 1;
	while (j >= 0 && (s[j] == '\n' || s[j] == '\t' || s[j] == ' '))
		j--;
	if ((dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s) - i - j + 1))))
	{
		size = ft_strlen(s) - (ft_strlen(s) - j) + 1;
		j = -1;
		while (++j < size - i)
			dst[j] = s[i + j];
		dst[j] = '\0';
		return (dst);
	}
	else
		return (NULL);
}

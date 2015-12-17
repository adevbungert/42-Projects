/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:14:57 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 18:08:17 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_next_world(const char *str, char c)
{
	while ((*str == c) && (*str != '\0'))
		str++;
	return (*str == '\0' ? NULL : str);
}

static const char	*ft_end_world(const char *str, char c)
{
	while (*str != c && *str != '\0')
		str++;
	return (str - 1);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	const char	*str;
	int			count;

	if (!s || !c)
		return (NULL);
	count = 0;
	str = s;
	while ((str = ft_next_world(str, c)) != NULL)
	{
		count++;
		str = ft_end_world(str, c) + 1;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = NULL;
	count = 0;
	while ((s = ft_next_world(s, c)) != NULL)
	{
		str = s;
		s = ft_end_world(s, c) + 1;
		tab[count++] = ft_strsub(str, 0, s - str);
	}
	return (tab);
}

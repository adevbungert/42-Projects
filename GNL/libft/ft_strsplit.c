/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:14:57 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 12:32:00 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_word(const char *s, char c)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s && *s != c)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

static int			nb_words(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			count;
	int			i;

	if (!s)
		return (NULL);
	count = nb_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			tab[i] = get_word(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

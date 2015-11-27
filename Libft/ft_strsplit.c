/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:14:57 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 16:05:09 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char **ft_get_tab(char const *s, char **tab, char c)
{
	const char	*tmp = s;
	char		*buf;
	size_t		count;

	buf = (char *)malloc(sizeof(*buf) * ft_strlen(s));
	count = 0;
	while (*tmp)
	{
		if (*tmp == c)
		{
			tmp++;
			continue;
		}
		while (*tmp != c)
		{
			buf[count] = *tmp;
			count++;
			tmp++;
		}
		buf[count] = '\0';
		if((*tab = ft_strdup(buf)) == NULL)
				return NULL;
		count = 0;
		tab++;
	}
	return (tab);
}

static char	**ft_strsplit_alloc(char const *s, char c)
{
	const char	*tmp = s;
	char		**tab;
	size_t		count;

	count = 0;
	while (*tmp)
	{
		if (*tmp++ == c)
			continue;
		count++;
		while (*tmp++ != c)
			;
	}
	if((tab = (char **)malloc(sizeof(*tab) * (count + 1))) == NULL)
		return NULL;
	tab = ft_get_tab(s, tab, c);
	tab[count] = NULL;
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	char		*tmp;
	char		**tab;

	tmp = (char *)s;
	tab = ft_strsplit_alloc(tmp, c);
	return (tab);
}

int main()
{
	char a[30] = "la vie est une fete";
	char **tab = ft_strsplit(a, ' ');
	while (*tab)
		printf("%s\n", *tab++);
}
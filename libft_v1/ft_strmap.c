/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:32:42 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:53:54 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	const char	*s1 = s;

	if (!s || !f)
		return (NULL);
	while (*s1 != '\0')
		++s1;
	if (!(str = (char *)malloc(sizeof(char) * (s1 - s + 1))))
		return (NULL);
	s1 = s;
	while (*s1 != '\0')
	{
		str[s1 - s] = f(*s1);
		s1++;
	}
	str[s1 - s] = '\0';
	return (str);
}

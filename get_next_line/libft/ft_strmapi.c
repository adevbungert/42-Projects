/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:52:14 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:56:46 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	const char		*s1;
	int				i;

	if (!s || !f)
		return (NULL);
	s1 = s;
	while (*s1 != '\0')
		++s1;
	if (!(str = (char *)malloc(sizeof(char) * (s1 - s + 1))))
		return (NULL);
	s1 = s;
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = f(i, *s1);
		i++;
		s1++;
	}
	str[i] = '\0';
	return (str);
}

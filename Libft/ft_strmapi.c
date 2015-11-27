/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:52:14 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:44:30 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	const char		*s1 = s;
	unsigned int	i;
	
	i = 0;
	str = ft_strnew(ft_strlen(s1));
	while (*s1)
	{
		*str++ = (*f)(i, *s1);
		i++;
		s1++;
	}
	return (str);
}
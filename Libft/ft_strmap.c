/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:32:42 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:44:20 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	const char	*s1 = s;
	
	str = ft_strnew(ft_strlen(s1));
	while (*s1)
	{
		*str++ = (*f)(*s1);
		s1++;
	}
	return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:41:09 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/16 19:25:32 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(s1 = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = f(s[i]);
		i++;
	}
	return (s1);
}

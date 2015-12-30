/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:58:56 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 11:02:28 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s1);
	tmp = s1;
	while (*s2)
	{
		tmp[i] = *s2;
		s2++;
		i++;
	}
	tmp[i] = '\0';
	return (s1);
}

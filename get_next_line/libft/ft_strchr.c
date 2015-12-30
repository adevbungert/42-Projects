/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:02:48 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 11:06:16 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	find;

	find = c;
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == find)
			return (tmp);
		tmp++;
	}
	if (*tmp == find)
		return (tmp);
	else
		return (NULL);
}

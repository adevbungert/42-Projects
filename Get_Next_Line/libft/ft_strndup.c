/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:36:35 by abungert          #+#    #+#             */
/*   Updated: 2015/12/08 16:42:05 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN(a,b) a<b?a:b

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	if (!(cpy = (char *)malloc(MIN(len + 1, n))))
		return (NULL);
	ft_strncpy(cpy, s1, n);
	return (cpy);
}

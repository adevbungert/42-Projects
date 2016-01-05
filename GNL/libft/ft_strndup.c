/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 11:00:18 by abungert          #+#    #+#             */
/*   Updated: 2015/12/30 11:05:35 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(cpy, s1, n);
	return (cpy);
}

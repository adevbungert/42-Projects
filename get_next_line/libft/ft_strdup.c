/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:12:50 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 12:20:00 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:08:40 by abungert          #+#    #+#             */
/*   Updated: 2015/12/09 18:12:23 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*str;

	str = s;
	while (*str != '\0')
		str++;
	while (*str != (char)c && str >= s)
		str--;
	return (*str == (char)c ? (char *)str : NULL);
}
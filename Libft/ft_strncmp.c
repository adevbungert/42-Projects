/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:52:21 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 14:27:55 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char uc1;
	unsigned char uc2;

	if (n == 0)
		return (0);
	while (n != 0 && *s1 == *s2)
	{
		if (n == 0 || *s1 == '\0')
			return (0);
		n--;
		s1++;
		s2++;
	}
	uc1 = ((unsigned char)*s1);
	uc2 = ((unsigned char)*s2);
	return ((uc1 < uc2) ? -1 : (uc1 - uc2));
}
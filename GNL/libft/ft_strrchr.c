/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:51:25 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 11:54:08 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	c_;
	int		len;

	len = ft_strlen(s);
	tmp = (char *)s + len;
	c_ = c;
	while (tmp >= s)
	{
		if (*tmp == c_)
			return (tmp);
		tmp--;
	}
	return (NULL);
}

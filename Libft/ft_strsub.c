/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:13:30 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 10:04:34 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	end;
	char			*str;
	char			*s1;

	*s1 = s[start];
	if ((str = (char *)malloc(sizeof(*str) * len + 1)) == NULL)
		return (NULL);
	 str = ft_strncpy(str, s1, len);
	 return (str);
}
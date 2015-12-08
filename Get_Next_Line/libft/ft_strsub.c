/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:13:30 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:58:36 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s)
		return ("");
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_memcpy(str, s + start, len);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:18:19 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 11:14:35 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*s1;

	s1 = s;
	s1 = ft_strrplc(s1, ' ', '\n', '\t', '');
	if ((str = ft_strdup(s1)) == NULL)
		return NULL;
	return (str);
}
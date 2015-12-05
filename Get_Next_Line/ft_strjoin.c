/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:39:07 by obengelo          #+#    #+#             */
/*   Updated: 2015/12/05 16:26:12 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (s1 != NULL && s2 != NULL)
	{
		string = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (string != NULL)
		{
			string = ft_strcpy(string, s1);
			return (ft_strcat(string, (char *)s2));
		}
	}
	return (NULL);
}

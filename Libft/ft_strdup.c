/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:04:32 by abungert          #+#    #+#             */
/*   Updated: 2015/11/26 17:35:46 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*cpy;

	if ((cpy = (char *)malloc(sizeof(*cpy) * (ft_strlen(str) + 1))) == NULL)
		return NULL;
	cpy = ft_strcpy(cpy, str);
	cpy[ft_strlen(str)] = '\0';
	return (cpy);
}

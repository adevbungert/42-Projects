/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:04:32 by abungert          #+#    #+#             */
/*   Updated: 2015/11/24 11:24:07 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int		ft_strlen(char *str);
char	*ft_strcpy(char *str);

char	*ft_strdup(char *str)
{
	char	*cpy;

	if (cpy = malloc((char *)sizeof(char * (ft_strlen(str) + 1)) == 0))
		return NULL;
	return (cpy = ft_strcpy(cpy, str));
	free(cpy);
}

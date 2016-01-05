/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:05:20 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:36:58 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(*s) * size + 1)))
	{
		ft_bzero((void *)s, size);
		return (s);
	}
	else
		return (NULL);
}

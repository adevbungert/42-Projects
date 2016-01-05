/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:57:57 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/12 13:18:26 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *s;

	if ((s = (unsigned char *)malloc(sizeof(*s) * size)))
	{
		ft_bzero(s, size);
		return ((void *)s);
	}
	else
		return (NULL);
}

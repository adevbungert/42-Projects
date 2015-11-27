/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:10:34 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:52:35 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*b;

	if((b =(unsigned char *)malloc(sizeof(*b) * size)) == NULL)
		return NULL;
	b = ft_bzero(b, size);
	return ((void *)b);
}
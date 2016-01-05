/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:38:21 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/12 14:27:16 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(*new))))
	{
		if ((new->content = ft_memalloc(content_size)))
			new->content = ft_strcpy(new->content, content);
		new->content_size = content_size;
		if (!new->content)
			new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

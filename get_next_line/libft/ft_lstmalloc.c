/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:16:38 by abungert          #+#    #+#             */
/*   Updated: 2015/12/07 18:28:38 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lst1new(void const *content, size_t content_size)
{
	t_list1			*my_list;

	if (!(my_list = (t_list1 *)malloc(sizeof(*my_list))))
		return (NULL);
	my_list->next = NULL;
	my_list->content = NULL;
	my_list->content_size = 0;
	if (content == NULL)
		return (my_list);
	if (!(my_list->content =
		(void *)malloc(sizeof(*content) * content_size + 1)))
		return (NULL);
	my_list->content = ft_memcpy(my_list->content, content, content_size);
	my_list->content_size = content_size;
	return (my_list);
}

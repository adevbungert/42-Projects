/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:02:49 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:22:33 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin_list;

	if (!f)
		return (NULL);
	begin_list = NULL;
	while (lst)
	{
		if (!(tmp = ft_lstdup(f(lst))))
			return (NULL);
		begin_list = ft_lstpb(begin_list, tmp);
		lst = lst->next;
	}
	return (begin_list);
}

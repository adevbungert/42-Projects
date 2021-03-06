/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_before.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:25:24 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:59:10 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_before(t_list **alst, t_list *target, t_list *new)
{
	t_list	*previous;
	t_list	*node;

	node = *alst;
	previous = *alst;
	while (node)
	{
		if (node == target)
		{
			if (node == *alst)
				ft_lstadd_beginning(alst, new);
			else
			{
				new->next = target;
				previous->next = new;
			}
			break ;
		}
		previous = node;
		node = node->next;
	}
}

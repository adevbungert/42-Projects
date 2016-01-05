/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:25:30 by abungert          #+#    #+#             */
/*   Updated: 2015/12/03 13:10:08 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*lst_tmp;

	lst_tmp = lst;
	while (lst_tmp != NULL)
	{
		(*f)(lst_tmp);
		lst_tmp = lst_tmp->next;
	}
}

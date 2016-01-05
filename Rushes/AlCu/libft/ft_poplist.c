/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poplist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:20:28 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/18 11:25:48 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_poplist(t_list **begin_all, t_list *begin)
{
	t_list	*cur;
	t_list	*tmp_cur;

	cur = *begin_all;
	tmp_cur = NULL;
	while (cur)
	{
		if (cur == begin)
		{
			if (tmp_cur)
				tmp_cur->next = cur->next;
			else
				*begin_all = cur->next;
			ft_memdel((void **)(&cur));
			break ;
		}
		tmp_cur = cur;
		cur = tmp_cur->next;
	}
}

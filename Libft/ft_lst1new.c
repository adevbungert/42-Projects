/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:16:38 by abungert          #+#    #+#             */
/*   Updated: 2015/12/07 20:52:18 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1		*ft_lst1new(int fd)
{
	t_list1			*my_list;

	if (!(my_list = (t_list1 *)malloc(sizeof(*my_list))))
		return (NULL);
	my_list->next = NULL;
	my_list->content = NULL;
	my_list->n_fd = fd;
	return (my_list);
}

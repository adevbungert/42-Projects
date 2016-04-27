/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_beginning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:08:22 by abungert           #+#    #+#             */
/*   Updated: 2016/01/13 13:54:34 by abungert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_beginning(t_list **alst, t_list *new)
{
	if (*alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

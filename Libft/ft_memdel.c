/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:11:21 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 14:06:31 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void	**ap)
{
	unsigned char	**ucap;

	ucap = (unsigned char **)ap;
	while(**ucap)
	{
		free (*ucap);
		*ucap++ = NULL;
	}
}
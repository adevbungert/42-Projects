/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:12:45 by abungert          #+#    #+#             */
/*   Updated: 2016/02/10 15:36:49 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler_signal(int code)
{
	if (code == SIGINT)
	{
		ft_putendl("");
	}
}

void	catch_signal(void)
{
	signal(SIGINT, handler_signal);
}
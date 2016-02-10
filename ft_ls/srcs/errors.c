/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/29 10:49:55 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *message, int time)
{
	if (time == 1)
	{
		ft_putstr("ft_ls: ");
		perror(message);
	}
	else if (time == 2 && errno != 2)
	{
		ft_putstr(message);
		ft_putendl(":");
		ft_putstr("ft_ls: ");
		perror(message);
	}
}

void	error_message(char *message, int terminate)
{
	ft_putcolor("ERROR: ", "red");
	perror(message);
	if (terminate)
		exit(0);
}

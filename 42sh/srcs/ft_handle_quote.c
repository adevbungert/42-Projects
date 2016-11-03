/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:10:47 by abungert          #+#    #+#             */
/*   Updated: 2016/04/22 11:53:21 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

char	*ft_handle_quote(void)
{
	char	*specials;

	specials = ft_strdup("\"'");
	while (*specials)
	{
		if (ft_count_char(g_main_line.cmd, *specials) % 2 != 0)
			return (ft_del_char(ft_complete_cmd(*specials, "\n"), *specials));
		specials++;
	}
	return (g_main_line.cmd);
}

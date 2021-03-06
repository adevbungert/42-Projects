/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:15:30 by abungert          #+#    #+#             */
/*   Updated: 2016/11/03 19:15:32 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_insert(char *string, char *insert, size_t start)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	total_len;
	char	*new;

	if (insert == NULL)
		return (string);
	i = 0;
	j = 0;
	k = 0;
	total_len = ft_strlen(string) + ft_strlen(insert);
	new = ft_strnew(total_len);
	while (i < total_len)
	{
		if (i == start)
		{
			while (i < start + ft_strlen(insert))
				new[i++] = insert[j++];
		}
		new[i] = string[k];
		i++;
		k++;
	}
	return (new);
}

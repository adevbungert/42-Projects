/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:18:19 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:25:28 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isspec(char c)
{
	return (c == ' '
		|| c == '\n'
		|| c == '\t');
}

char			*ft_strtrim(char const *s)
{
	int			start;
	int			end;
	char		*str;
	int			len;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (isspec(s[start]) && s[start] != '\0')
		start++;
	while (isspec(s[end]) && end > 0)
		end--;
	len = (end == 0) ? 0 : end - start + 1;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while ((start + len) <= end)
	{
		str[len] = s[start + len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

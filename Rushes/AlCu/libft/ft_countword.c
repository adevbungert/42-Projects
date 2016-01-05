/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:36:34 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/03 10:24:31 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countword(const char *s, char c)
{
	int		count;
	int		i;
	int		during_word;

	during_word = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && during_word == 1)
		{
			count++;
			during_word = 0;
		}
		if (s[i] != c && during_word == 0)
			during_word = 1;
		i++;
	}
	if (during_word)
		count++;
	return (count);
}

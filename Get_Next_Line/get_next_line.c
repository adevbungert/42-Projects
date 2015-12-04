/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:19:06 by abungert          #+#    #+#             */
/*   Updated: 2015/12/04 21:28:52 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*	Check_EOL = 1 if occur'\n' 
*	Check_EOL = 0 if noccur'\n'
*	Check_EOL = -1 if error
*/

int	static		check_eol_tab(char **tab, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *tab;
	while (tmp[i])
	{
		if (tmp[i] == '\n' || tmp[i] == '\0')
		{
			if (!(*line = ft_strsub(tmp, 0, i)))
				return (-1);
			if(!(tmp = ft_strdup(&(tmp[i + 1]))))
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int static		check_eol_buf(char **tab, char **line, char *BUF)
{
	int		i;

	i = 0;
	while (BUF[i])
	{
		if (BUF[i] == '\n')
		{
			if(!(*line = ft_strsub(BUF, 0, i - 1)))
				return (-1);
			if(!(*tab = ft_strjoin(*tab, &BUF[i + 1])))
				return (-1);
			return (1);
		}
		i++;
	}
	if (i > 0)
		if (!(*tab = ft_strjoin(*tab, BUF)))
			return (-1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	char static		*tab = NULL;
	char			*BUF;
	int				ret;

	if (!tab)
		if (!(tab = (char *)malloc(sizeof(*tab) * BUF_SIZE + 1)))
			return (-1);
	if (!(check_eol_tab(&(tab), line)))
	{
		if (!(BUF = (char *)malloc(sizeof(*BUF) * BUF_SIZE + 1)))
			return (-1);
		while (!(check_eol_buf(&(tab), line, BUF)))
		{
			if (!(ret = read(fd, BUF, BUF_SIZE))) 
				break ;
			BUF[ret] = '\0';
		}
		free(BUF);
		BUF = NULL;
	}
	if (ft_strlen(tab) != 0)
		return (1);
	else
		return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:19:06 by abungert          #+#    #+#             */
/*   Updated: 2015/12/05 14:39:41 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
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
			if (tmp[i] == '\0')
				return (0);
			if(!((*tab) = ft_strdup(&(tmp[i + 1]))))
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
	char	*tmp;

	i = 0;
	while (BUF[i])
	{
		if (BUF[i] == '\n' || BUF[i] == '\0')
		{
			if (tab)
			{
				tmp = ft_strsub(BUF, 0, i);
				if(!(*line = ft_strjoin(*tab, tmp)))
					return (-1);
			}
			if (BUF[i + 1])
			{
				if(!(*tab = ft_strdup(&(BUF[i + 1]))))
					return (-1);
			}
			else
				ft_strdel(tab);
			return (1);
		}
		i++;
	}
	if (i > 0)
	{
		if (!(*tab = ft_strjoin(*tab, BUF)))
			return (-1);
	}
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
		if (!(BUF = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
			return (-1);
		while (!(check_eol_buf(&(tab), line, BUF)))
		{
			ret = read(fd, BUF, BUF_SIZE);
			if (ret == 0)
				break ;
			if (ret == -1)
				return (-1);
			BUF[ret] = '\0';
			// ft_putstr(" ---- ");
			// ft_putstr(BUF);
			// ft_putendl(" ------- ");
		}
		free(BUF);
		BUF = NULL;
	}
	// printf("TAB --->%s<--- \n", tab);
	// printf("size %d\n", (int)ft_strlen(tab));
	if (!tab || ft_strlen(tab) != 0)
	{
		// printf("HELLOOOOOOOOOOO\n");
		return (1);
	}
	else
	{
		// printf("MERDEEEEEEEEEE\n");
		return (0);
	}
}

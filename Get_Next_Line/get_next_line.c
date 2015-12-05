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
    printf("\n---Je rentre dans tab---\n");
	while (tmp[i])
	{
        printf("\n---Je rentre dans while de tab---\n");     
		if (tmp[i] == '\n' || tmp[i] == '\0')
		{
            printf("\n---Je rentre dans if de tab---\n");
			if (!(*line = ft_strsub(tmp, 0, i)))
				return (-1);
            if (tmp[i] == '\0')
                return (0);
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
    printf("\n---Je rentre dans buf---\n");
	while (BUF[i])
	{
        printf("\n---Je rentre dans while de buf---\n");
		if (BUF[i] == '\n' || BUF[i] == '\0')
		{
            printf("\n---Je rentre dans if de buf---\n");
            printf("\n--i = %d-- --BUFF[i - 1] = %c--\n", i, BUF[i-1]);
			if(!(*line = ft_strsub(BUF, 0, i)))
				return (-1);
			if(!(*tab = ft_strjoin(*tab, &BUF[i + 1])))
				return (-1);
            printf("\n>>>>*BUF = %s<<<<\n", &BUF[i + 1]);
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
		}
		free(BUF);
		BUF = NULL;
	}
	if (ft_strlen(tab) != 0)
		return (1);
	else
		return (0);
}

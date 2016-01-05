/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:35:56 by abungert          #+#    #+#             */
/*   Updated: 2015/12/20 16:41:27 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		read_file(char *file, t_lst **begin)
{
	int		fd;
	char	*str;
	int		res;
	int		nb;
	int		error;

	error = 0;
	res = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (res > 0 || res == -2)
	{
		res = get_next_line(fd, &str);
		if (res != 0 && ft_strlen(str) > 0 && (nb = check_str(str)))
			add_to_list(nb, begin);
		else if (res != 0)
			error = 1;
	}
	if (!error)
		return (1);
	else
		return (0);
}

int		read_standard_input(t_lst **begin)
{
	int		fd;
	int		res;
	char	*str;
	int		nb;

	res = 1;
	fd = 0;
	while (res > 0)
	{
		aff_map(*begin);
		res = get_next_line(0, &str);
		if (str[0] == 0)
			break ;
		else if ((nb = check_str(str)))
			add_to_list(nb, begin);
		else
			return (0);
	}
	return (1);
}

t_lst	*get_last_line(t_lst **begin)
{
	t_lst	*cur;

	cur = *begin;
	while (cur->next && cur->next->nb != 0)
		cur = cur->next;
	if (cur->nb < 0)
		return (NULL);
	return (cur);
}

int		count_all_matches(t_lst *begin)
{
	t_lst	*cur;
	int		res;

	res = 0;
	cur = begin;
	while (cur)
	{
		res += cur->nb;
		cur = cur->next;
	}
	return (res);
}

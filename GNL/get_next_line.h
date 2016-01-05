/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:14:45 by abungert          #+#    #+#             */
/*   Updated: 2015/12/30 15:35:12 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct				s_list_gnl
{
	int						fd;
	char					*str;
	struct s_list_gnl		*next;
}							t_list_gnl;

int							get_next_line(int const fd, char **line);

#endif

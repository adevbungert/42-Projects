/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:03:03 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/20 15:27:35 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include "../libft/includes/libft.h"

typedef struct		s_fd
{
	int				fd;
	t_list			*buff;
	struct s_fd		*next;
}					t_fd;

# define BUFF_SIZE 1

int					get_next_line(int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:02:58 by abungert          #+#    #+#             */
/*   Updated: 2015/12/07 12:48:27 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 500

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>

int			get_next_line(int const fd, char **line);

#endif

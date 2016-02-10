/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:25:27 by antoinebungert    #+#    #+#             */
/*   Updated: 2016/02/01 11:56:16 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_link(t_files *file)
{
	char	buf[1024];
	char	*file_path;
	ssize_t	size;

	file_path = ft_strjoin_nolimit(0, file->parent_dir, "/", file->name, NULL);
	if ((size = readlink(file_path, buf, sizeof(buf) - 1)) != -1)
		buf[size] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buf);
}

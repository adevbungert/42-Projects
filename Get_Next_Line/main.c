/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:21:50 by abungert          #+#    #+#             */
/*   Updated: 2015/12/04 21:48:37 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;
	int		ret;

	if ((fd = open("fichier_test.txt", O_RDONLY)))
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
		while (ret != 0 || ret != -1)
		{
			ret = get_next_line(fd, &line);
			printf("%s\n", line);
		}
		if (ret == -1)

		// while ((ret = get_next_line(fd, &line)) == 1)
		// 	printf("%s\n", line);
		// if (ret == -1)
			printf("Error");
		// else
		// 	printf("File finished");
	}
	return (0);
}
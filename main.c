/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:28:30 by abungert          #+#    #+#             */
/*   Updated: 2015/12/08 15:48:55 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int     main(void)
{
        int     fd;
        char    *line;
        int     ret;

        ret = 1;
        line = NULL;
        if ((fd = open("test.txt", O_RDONLY)))
        {
            while (ret != 0 && ret != -1)
            {
                ret = get_next_line(fd, &line);
                if (line)
                    ft_putendl(line);
                free(line);
                line = NULL;
            }
            if (ret == -1)
            printf("Error");
        }
        return (0);
}

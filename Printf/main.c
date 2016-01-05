/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:00:39 by abungert          #+#    #+#             */
/*   Updated: 2016/01/05 16:39:36 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	char nom[] = "Antoine";
	int	age = 22;

	printf ("Characters: %c %c %C \n", 'a', 65, 'a');
   	printf ("Decimals: %d, %i, %D \n", 1977, 1977, 1977);
   	printf ("Preceding with blanks: %10d \n", 1977);
   	printf ("Preceding with zeros: %010d \n", 1977);
   	printf ("Some different radices: %d %x %X %o %#x %#X %#o \n", 100, 100, 100, 100, 100, 100, 100);
   	printf ("Width trick: %*d \n", 10, 10);
   	printf ("%s \n", "A string");
   	printf ("No conversion: %% \n");
   	printf ("Unisgned Decimal: %u \n", -1);
   	printf ("Left justify: %-10d \n", 1977);
   	printf ("Space: %       d \n", 1977);
   	printf("%s\n", "TESTS POUSSES");
   	printf("4567 |%-10]5d| plip\n", 12);
    printf("4567 |%10]5d| plip\n", 12);
    printf("|%10.5d|\n", -12);
    printf("|%10d|\n", -12);
    printf("|%010d|\n", -12); 
    printf("|%-10.5d|\n", -12);
    printf("|%-010.5d|\n", -12);
   return 0;
	return (0);
}

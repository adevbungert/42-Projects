/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:36:35 by abungert          #+#    #+#             */
/*   Updated: 2015/12/08 13:03:38 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(char *str, size_t n)
{
    char    *cpy;

    if ((cpy = (char *)malloc(sizeof(*cpy) * n + 1)) == NULL)
        return (NULL);
    cpy = ft_strncpy(cpy, str, n); 
    return (cpy);
}

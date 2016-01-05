/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:18:17 by abungert          #+#    #+#             */
/*   Updated: 2016/01/05 15:17:35 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
char	*ft_itoa(int n);
void	ft_putstr(const char *s);

# define ABS(v) ((v) < 0 ? -(v) : (v))

#endif
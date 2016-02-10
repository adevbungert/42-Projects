/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 17:06:17 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAG_STRUCT_H
# define TAG_STRUCT_H

typedef struct		s_tag
{
	char	specifier;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_sharp;
	char	flag_zero;
	char	has_width;
	int		width;
	char	has_precision;
	int		precision;
	char	length;
}					t_tag;

#endif

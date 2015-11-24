/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:52:21 by abungert          #+#    #+#             */
/*   Updated: 2015/11/24 11:52:37 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

char	*ft_strcat(char *dest, char	*src)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if((dest = malloc((char *)sizeof(char * (ft_strlen(dest) + ft_strlen(src))))) == 0)
		return NULL;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
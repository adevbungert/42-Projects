/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:48:17 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 16:40:31 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
/* 
** 1ere partie
*/
void	*ft_memset(void *s, int c, size_t len);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strlen(const char *s);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strcat(char *dest, char	*src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_isascii(char c);
int		ft_isprint(int c);
char	ft_toupper(char c);
char	ft_tolower(char c);

/* 
** 2eme partie
*/
void	*ft_memalloc(size_t size);
void 	ft_memdel(void **ap);
char 	*ft_strnew(size_t size);
void 	ft_strdel(char **as);
void 	ft_strclr(char *s);
void 	ft_striter(char *s, void (*f)(char *));
void 	ft_striteri(char *s, void (*f)(unsigned int, char *));
char 	*ft_strmap(char const *s, char (*f)(char));
char 	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int 	ft_strequ(char const *s1, char const *s2);
int 	ft_strnequ(char const *s1, char const *s2, size_t n);
char 	*ft_strsub(char const *s, unsigned int start, size_t len);
char 	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_strtrim(char const *s);
char 	**ft_strsplit(char const *s, char c);
char 	*ft_itoa(int n);
void 	ft_putchar(char c);
void 	ft_putstr(char const *s);
void 	ft_putendl(char const *s);
void 	ft_putnbr(int n);
void 	ft_putchar_fd(char c, int fd);
void 	ft_putstr_fd(char const *s, int fd);
void 	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);


/* 
** Option
*/
char	*ft_strplc(char *s, char c, char c_new);
char	*ft_strrplc(char *s, char c1, char c2, char c3, char c_new);
char	*ft_streverse(char *s);
int 	ft_power(int power, int nb);

#endif

int		ft_strlen(char	*str);
char 	*ft_strnew(size_t size);

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
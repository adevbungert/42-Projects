*char	ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str[i]);
		else
			i++;
	}
	if (c == 0)
		return (str[i]);
	else
		return NULL;
}
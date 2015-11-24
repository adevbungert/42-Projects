char	*ft_strstr(const char *s1, const char *s2, int n)
{
	int i;
	int j;

	i = 0;
	if (!s2)
		return (s1);
	while (s1[i] != '\0' || i <= n)
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			while ((s2[j] == s1[i]) && (s2[j] != '\0' || s1[i] != '\0'))
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return (s1[i]);
		}
		else
			i++;
	}
	return NULL;
}
char	ft_tolower(char c)
{
	if (c >= 101 && c <= 132)
		return (c + 40);
	else
		return (c);
}
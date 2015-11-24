char	ft_toupper(char c)
{
	if (c >= 141 && c <= 172)
		return (c - 40);
	else
		return (c);
}
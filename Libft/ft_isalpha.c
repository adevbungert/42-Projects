
int		ft_isalpha(char c)
{
	if ((c >= 101 && c <= 132) || (c >= 141 && c <= 172))
		return (1);
	else
		return (0);
}
void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while ((b[i] != '\0') && (i <= len))
	{
		b[i] = c;
		i++;
	}
	return (b);
}
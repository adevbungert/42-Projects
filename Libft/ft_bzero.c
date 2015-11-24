void	*bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while ((b[i] != '\0') && (i <= n))
	{
		b[i] = 0;
		i++;
	}
	return (b)
}
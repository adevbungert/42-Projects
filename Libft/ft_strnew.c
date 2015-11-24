#include <stdlib.h>
void	*memset(void *b, int c, size_t len);

char	*ft_strnew(size_t size)
{
	char	*str;
	
	if((str = (char *)malloc(sizeof(char * size))) == 0)
		return NULL;
	str = ft_bzero(b, size);
	return (str);
}
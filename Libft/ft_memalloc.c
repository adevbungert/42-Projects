#include <stdlib.h>
void	*memset(void *b, int c, size_t len);

void	*ft_memalloc(size_t size)
{
	void	*b;

	if((b =(void *)malloc(sizeof(size))) == 0)
		return NULL;
	b = ft_bzero(b, size);
	return (b);
}
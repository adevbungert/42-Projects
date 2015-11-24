#include <stdlib.h>

void	ft_memdel(void	**ap)
{
	while(**ap)
	{
		free (*ap);
		*ap = NULL;
		*ap++;
	}
}
#include <stdlib.h>

void	ft_strdel(char **as)
{
	while (**as[i] != '\0')
	{
		free(*as);
		*as = NULL;
		*as++;
	}
}
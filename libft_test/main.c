#include "libft.h"
#include <stdio.h>


int	main(int ac, char **av)
{
  printf("%s\n", ft_strchr("Salut      ", ':' + 0b10000000));
  return(0);
}

#include "push_swap.h"

int		check_pile(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
	i = 1;
	while (i < length)
	{
		if (pile[i - 1] < pile[i])
			return (0);
		i++;
	}
	return (1);
}

int		check_pile_reverse(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
	i = 1;
	while (i < length)
	{
		if (pile[i - 1] > pile[i])
			return (0);
		i++;
	}
	return (1);
}
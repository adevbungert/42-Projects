#include "../ft_select.h"

int			see_key()
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			ft_printf("Ctlr+d, on quitte ! \n");
			return (0);
		}
	}
	return (0);
}

int					main(int ac, char **av, char **env)
{
	char			*name_term;
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	see_key();
	return (0);
}

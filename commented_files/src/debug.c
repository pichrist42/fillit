#include "../includes/fillit.h"

void	print_int(char *s, int val, int end)
{
	if (DEBUG)
	{
		ft_putstr(s);
		ft_putnbr(val);
		if (end)
			ft_putchar('\n');
	}
}

void	print_char(char *s, char val, int end)
{
	if (DEBUG)
	{
		ft_putstr(s);
		if (val != '\n')
			ft_putchar(val);
		else
			ft_putstr("\\n");
		if (end)
			ft_putchar('\n');
	}
}

void	print_str(int tab, char *s, int end)
{
	if (DEBUG)
	{
		for (int i = 0; i < tab; ++i)
			ft_putstr("\t");
		ft_putstr(s);
		if (end)
			ft_putchar('\n');
	}
}

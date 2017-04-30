/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:41:20 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/30 21:58:49 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	tetri_lstiter(t_tetri *lst, void (*f)(t_tetri *elem))
{
	if (lst && f)
	{
		// while (lst)
		// {
		// 	f(lst);
		// 	lst = lst->next;
		// }

		// f(lst->prev);
		f(lst);
		int stop = 0;
		while (!stop)
			if (lst->next)
			{
				lst = lst->next;
				f(lst);
			}
			else
				stop = 1;
	}
}

void	display_tetri(t_tetri *t)
{
	if (DEBUG)
	{
		print_char("", t->alpha, 1);
		for (int i = 0; i < 4; ++i)
		{
			print_int("(", t->block[i][0], 0);
			print_int(" ; ", t->block[i][1], 0);
			ft_putendl(")");
		}
	}
}

void	stuff(char *file_content, size_t sq_size, char *square)
{
	t_tetri	*first;
	int		exit_code;
	int		d;

	d = 0;
	exit_code = 0;
	first = find_tetri(file_content, 0, 0, -1);
	
	// tetri_lstiter(first, *display_tetri);
	// ft_putendl("");
/*
	while (t->next)
	{
		ft_putchar(t->alpha);
		ft_putendl("");
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				ft_putnbr(t->block[i][j]);
				if (!(j % 2))
					ft_putstr(" - ");
			}
			ft_putendl("");
		}
		if (t->next)
		{
			ft_putendl("\nnext");
			t = t->next;
		}
		ft_putendl("\nover");
	}
*/
	while (!exit_code)
	{
		sq_size = (++d > 1) ? ++sq_size : sq_size;
		square = gen_square(sq_size);
		square = the_mind(square, sq_size, first, 0);
		exit_code = ft_strncmp(square, "too small", ft_strlen("too small"));
	}
	if (!exit_code)
		ft_putendl("Error during the resolution of the problem.");
	else
		display_square(square);
		if (DEBUG_FT)
			print_str(0, "\nend", 1);
}

int		main(int ac, char **av)
{
	size_t	sq_size;
	char	*file_content;
	char	*square;

	if (ac != 2)
		ft_putendl(\
			"Incorrect number of arguments.\nUsage : ./fillit file.txt");
	else
	{
		if ((file_content = read_file(av[1])))
		{
			if (parse_file(file_content))
			{
				// ft_putendl("file parsed and valid");
				sq_size = find_square_size(file_content);
				stuff(file_content, sq_size, square);
			}
			else{
				// print_str(1, "coucou2", 1);
				ft_putendl("error");
			}
		}
		else{
			// print_str(1, "coucou", 1);
			ft_putendl("error");
		}
	}
	return (0);
}

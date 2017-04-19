/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:41:20 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/19 17:37:00 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	stuff(char *file_content, size_t sq_size, char *square)
{
	t_tetri	*t;
	int		exit_code;
	int		d;

	d = 0;
	exit_code = 0;
	t = find_tetri(file_content, 0, 0, -1, NULL);
	while (!exit_code && !d++)
	{
		square = gen_square(++sq_size);
		square = the_mind(square, t, sq_size);
		exit_code = ft_strncmp(square, "too small", \
ft_strlen("too small"));
	}
	if (!exit_code)
		ft_putendl("Error during the resolution of the problem.");
	else
		display_square(square);
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
			if (!parse_file(file_content))
			{
				sq_size = find_square_size(file_content);
				stuff(file_content, sq_size, square);
			}
			else
				ft_putendl(\
"Error : file is in an incorrect format. Please refer to the program notice.");
		else
			ft_putendl("Error : file can't be read.");
	}
	return (0);
}

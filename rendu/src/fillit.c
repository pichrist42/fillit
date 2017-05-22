/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:57 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:46:06 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	main_sub(char *file_content, size_t sq_size, char *square)
{
	t_tetri	*first;
	int		exit_code;
	int		limiter;

	limiter = 0;
	exit_code = 0;
	first = find_tetri(file_content, 0, 0, -1);
	while (!exit_code)
	{
		sq_size = (++limiter > 1) ? ++sq_size : sq_size;
		square = gen_square(sq_size);
		square = the_mind(square, sq_size, first, 0);
		exit_code = ft_strncmp(square, "too small", ft_strlen("too small"));
	}
	if (!exit_code)
		ft_putendl("error");
	else
		display_square(square);
}

int		main(int ac, char **av)
{
	size_t	sq_size;
	char	*file_content;

	if (ac != 2)
		ft_putendl("Usage : ./fillit file.txt");
	else
	{
		if ((file_content = read_file(av[1])))
			if (parse_file(file_content))
			{
				sq_size = find_square_size(file_content);
				main_sub(file_content, sq_size, NULL);
			}
			else
				ft_putendl("error");
		else
			ft_putendl("error");
	}
	return (0);
}

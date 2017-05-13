/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:57 by pichrist          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/05/13 20:28:25 by flseaill         ###   ########.fr       */
=======
/*   Updated: 2017/05/13 20:42:20 by pichrist         ###   ########.fr       */
>>>>>>> a79cfa3faa917194a380661f248fbd6bf93772c7
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit/fillit.h"
<<<<<<< HEAD
#include "../../includes/libft/libft.h"
=======
>>>>>>> a79cfa3faa917194a380661f248fbd6bf93772c7

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
		ft_putendl("Error during the resolution of the problem.");
	else
		display_square(square);
}

int		main(int ac, char **av)
{
	size_t	sq_size;
	char	*file_content;

	if (ac != 2)
		ft_putendl(\
			"Incorrect number of arguments.\nUsage : ./fillit file.txt");
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

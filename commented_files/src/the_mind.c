/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/22 09:53:20 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		formula(size_t sq_size, t_tetri *t, int i)
{
	// if (sq_size < 4)
		return (t->block[i][0] + t->block[i][1] * (sq_size + 1));
	// else if (sq_size > 4)
	// 	return (t->block[i][0] + t->block[i][1] * (4 - sq_size));
}

int		try_place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	int i = -1, ok = 1;
	while (++i < 4 && ok)
		if (square[formula(sq_size, t, i) + offset] != '.')
			ok = 0;
	return (ok);
}

char	*place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	int i = -1;
	while (++i < 4)
		square[formula(sq_size, t, i) + offset] = t->alpha;
	print_str(0, square, 0);
	if (t->next)
		return (the_mind(square, sq_size, t->next, 0));
	return (square);
}

void	clean_tetri(char *square, size_t sq_size, t_tetri *t, int offset)
{
	int i = -1;
	print_str(2, "before cleaning", 1);
	print_str(0, square, 0);
	while (square[++i])
		if (square[i] == t->alpha)
			square[i] = '.';
	print_str(2, "after cleaning", 1);
	print_str(0, square, 0);
}

char	*the_mind(char *square, size_t sq_size, t_tetri *t, int offset)
{
	print_char("the_mind - tetri ", t->alpha, 0);
	print_int(" - offset ", offset, 0);
	print_int(" - sq_size ", sq_size, 1);
	int again = 1;
	if (offset == -1)
	{
		while (square[++offset] != t->alpha)
			;
		++offset;
		while (again)
		{
			int block_nb = -1;
			int i = -1;
			while (++block_nb < 4)
				while (square[++i])
					if (square[i + offset] == t->alpha)
						again = 0;
			if (again)
				++offset;
		}
		print_int("\told offset ", offset, 1);
		print_str(1, "the_mind -> cleaning", 1);
		clean_tetri(square, sq_size, t, offset);
		if (DEBUG)
			getchar();
		if (++offset < ft_strlen(square))
			return (the_mind(square, sq_size, t, offset));
	}
	if (try_place_tetri(square, sq_size, t, offset))
	{
		print_str(1, "the_mind -> place_tetri", 1);
		return (place_tetri(square, sq_size, t, offset));
	}
	if (++offset < ft_strlen(square))
		return (the_mind(square, sq_size, t, offset));
	if (!(t->prev))
		return ("too small");
	print_str(1, "return to prev tetri", 1);
	return (the_mind(square, sq_size, t->prev, -1));
}

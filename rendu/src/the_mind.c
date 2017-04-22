/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/22 09:22:55 by pichrist         ###   ########.fr       */
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
	if (t->next)
		return (the_mind(square, sq_size, t->next, 0));
	return (square);
}

void	clean_tetri(char *square, size_t sq_size, t_tetri *t, int offset)
{
	int i = -1;
	while (++i < 4)
		square[formula(sq_size, t, i) + offset] = '.';
}

int do_clean = 1;

char	*the_mind(char *square, size_t sq_size, t_tetri *t, int offset)
{
	int again = 1;
	if (offset == -1)
	{
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
		if (do_clean)
			do_clean = 0;
		else
			return "end";
		clean_tetri(square, sq_size, t, offset);
		if (++offset < ft_strlen(square))
			return (the_mind(square, sq_size, t, offset));
	}
	if (try_place_tetri(square, sq_size, t, offset))
		return (place_tetri(square, sq_size, t, offset));
	if (++offset < ft_strlen(square))
		return (the_mind(square, sq_size, t, offset));
	if (!(t->prev))
		return ("too small");
	return (the_mind(square, sq_size, t->prev, -1));
}

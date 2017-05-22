/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:43:26 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*the_mind(char *square, size_t square_size, t_tetri *t, int rollback)
{
	int	offset;

	rollback = 0;
	while (1)
	{
		offset = the_mind_sub(&square, square_size, t, rollback);
		if (the_mind_tri(square, square_size, t, &offset))
		{
			square = the_mind_quad(square, square_size, t, offset - 1);
			if (!(t->next))
				return (square);
			if (the_unknown(square, t))
				return ("too small");
			rollback = 0;
			t = t->next;
			continue;
		}
		if ((!t->prev))
			return ("too small");
		rollback = 1;
		t = t->prev;
	}
}

int		the_mind_sub(char **square, size_t square_size, t_tetri *t, \
	int rollback)
{
	int block_nb;
	int offset;

	offset = -1;
	if (rollback)
	{
		while (rollback)
		{
			++offset;
			rollback = 0;
			block_nb = -1;
			while (++block_nb < 4 && !rollback)
				if ((*square)[formula(square_size, t, block_nb) + offset] != \
					t->alpha)
					rollback = 1;
		}
		block_nb = -1;
		while ((*square)[++block_nb])
			if ((*square)[block_nb] == t->alpha)
				(*square)[block_nb] = CHAR_SPACE;
	}
	return (offset);
}

int		the_mind_tri(char *square, size_t square_size, t_tetri *t, int *offset)
{
	int block_nb;
	int found_place;

	found_place = 0;
	while (++*offset < (int)ft_strlen(square) && !found_place)
	{
		block_nb = -1;
		found_place = 1;
		while (++block_nb < 4 && found_place)
			if (square[formula(square_size, t, block_nb) + *offset] \
				!= CHAR_SPACE)
				found_place = 0;
	}
	return (found_place);
}

char	*the_mind_quad(char *square, size_t square_size, t_tetri *t, int offset)
{
	int	block_nb;

	block_nb = -1;
	while (++block_nb < 4)
		square[formula(square_size, t, block_nb) + offset] = t->alpha;
	return (square);
}

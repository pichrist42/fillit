/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_bonus_mind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:53:59 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/23 03:56:05 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		formula(size_t square_size, t_tetri *t, int i)
{
	return (t->block[i][0] + t->block[i][1] * (square_size + 1));
}

int		the_unknown(char *square, t_tetri *t)
{
	int i;
	int nb_space;
	int nb_t;

	i = -1;
	nb_space = 0;
	nb_t = 0;
	while (square[++i])
		if (square[i] == CHAR_SPACE)
			++nb_space;
	while (t->next)
	{
		++nb_t;
		t = t->next;
	}
	return ((nb_t * 4 > nb_space) ? 1 : 0);
}

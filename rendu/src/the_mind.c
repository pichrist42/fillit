/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/19 21:18:51 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*the_mind(char *square, t_tetri *t, size_t sq_size)
{
	// int i; // curseur. pos de premier block du tetri
	// int block_placeable;
	// int block_nb;
	// int cleaned;

	// i = -1;
	// block_nb = -1;
	// block_placeable = 1;
	// cleaned = 0;
	// while (square[++i])
	// 	if (t->alpha == square[i])
	// 	{
	// 		square[i] = '.';
	// 		cleaned = 1;
	// 		if (block_nb == -1)
	// 			block_nb = i - 1;
	// 	}
	// i = -1;
	// if (cleaned)
	// 	i = block_nb + 1;
	// while (square[++i])
	// {
	// 	block_nb = -1;
	// 	block_placeable = 1;
	// 	while (++block_nb < 4 && block_placeable)
	// 		if (square[i + t->block[block_nb]] != '.')
	// 			block_placeable = 0;
	// 	if (block_placeable)
	// 	{
	// 		block_nb = -1;
	// 		while (++block_nb < 4)
	// 			square[i + t->block[block_nb]] = t->alpha;
	// 		if (!t->next)
	// 			return (square);
	// 		return (the_mind(square, t->next));
	// 	}
	// }
	// if (t->prev)
	// 	return (the_mind(square, t->prev));
	// else
	// 	return ("too small");
	return (square);
}

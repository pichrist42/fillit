/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/18 03:26:13 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		is_tetri_placeable(char *square, t_tetri *t, size_t sq_size)
{
	int		i;
	int		j;
	int		block_count;
	int		offset;

	i = -1;
	j = -1;
	block_count = -1;
	offset = sq_size - 4;
	while (block_count < 3 && ++i < 4 * (sq_size + 1) - 1)						// -1 because count from 0
	{
		if (t->block[++block_count])
		{

		}


		// if (square[++j + offset * j / sq_size] == '.')							// j / sq_size = nb lines dans square
	}
	return 1;
}

char	*place_tetri(char *square, t_tetri *t, size_t sq_size)
{
	return (square);
}

char	*the_mind(char *square, t_tetri *t, size_t sq_size)
{
	int		stop;

	stop = 0;
	while (!stop)
	{
		if (is_tetri_placeable(square, t, sq_size))
			square = place_tetri(square, t, sq_size);
		else
			stop = 1;
		if (!t->next)
			stop = 1;
		else
			t = t->next;
	}
	return square;
}




char	*the_old_mind(char *square, t_tetri *t)
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
	// 		if (DEBUG)
	// 			ft_putendl("cleaning");
	// 		square[i] = '.';
	// 		cleaned = 1;
	// 		if (block_nb == -1)
	// 			block_nb = i - 1;
	// 	}


	// i = -1;
	// if (cleaned)
	// {
	// 	if (DEBUG)
	// 		ft_putendl("new attempt");
	// 	i = block_nb + 1;
	// }
	// print_char("tetri ", t->alpha, 1);
	// while (square[++i])
	// {
	// 	block_nb = -1;
	// 	block_placeable = 1;
	// 	while (++block_nb < 4 && block_placeable)
	// 	{
	// 		if (DEBUG_POS)
	// 		{
	// 			print_int("placing cube ", block_nb, 1);
	// 			print_int("trying position ", i + t->block[block_nb], 0);
	// 			print_char(": ", square[i + t->block[block_nb]], 0);
	// 		}
	// 		if (square[i + t->block[block_nb]] != '.')
	// 		{
	// 			if (DEBUG_POS)
	// 				ft_putendl(" > pas ok");
	// 			block_placeable = 0;
	// 		}
	// 		else if (DEBUG_POS)
	// 			ft_putendl(" > ok");
	// 	}
	// 	if (block_placeable)
	// 	{
	// 		block_nb = -1;
	// 		while (++block_nb < 4)
	// 		{
	// 			if (DEBUG_PLACEMENT)
	// 			{
	// 				print_int("i ", i, 1);
	// 				print_int("block pos ", t->block[block_nb], 1);
	// 				print_int("value ", i + t->block[block_nb], 1);
	// 			}
	// 			square[i + t->block[block_nb]] = t->alpha;
	// 		}
	// 		if (DEBUG)
	// 		{
	// 			display_square(square);
	// 			getchar();
	// 			ft_putendl("------------------------------------------------");
	// 		}
	// 		if (!t->next)
	// 		{
	// 			if (DEBUG)
	// 				ft_putendl("end");
	// 			return (square);
	// 		}
	// 		if (DEBUG)
	// 			ft_putendl("next");
	// 		return (the_mind(square, t->next));
	// 	}
	// }
	// if (t->prev)
	// 	return (the_mind(square, t->prev));
	// else
	// 	return ("too small");
	return (square);
}

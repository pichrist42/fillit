/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/20 07:13:40 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// function
	// try to place tetri
		// success
			// place tetri
			// try next tetri
		// fail
			// is next pos available ?
				// yes > try next pos
				// no
					// is this tetri the first ?
						// yes
							// return error signal
						// no
							// return back to previous tetri, move it one pos

int		formula(size_t sq_size, t_tetri *t, int i)
{
	return (t->block[i][0] + t->block[i][1] * (sq_size - 4));
}

int		try_place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	print_int("try_place_tetri - sq_size ", sq_size, 0);
	if (t)
		print_char(" - tetri ", t->alpha, 0);
	else
		ft_putendl("\nerror : no tetri");
	print_int(" - offset ", offset, 1);

	int i;
	int ok;

	i = -1;
	ok = 1;
	while (++i < 4 && ok)
		if (square[formula(sq_size, t, i) + offset] != '.')
			ok = 0;
	return (ok);
}

char	*place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	print_int("place_tetri - sq_size ", sq_size, 0);
	print_char(" - tetri ", t->alpha, 0);
	print_int(" - offset ", offset, 1);
	
	int i;

	i = -1;
	while (++i < 4)
		square[formula(sq_size, t, i) + offset] = t->alpha;
	ft_putendl("place_tetri returning the_mind");;
	return (the_mind(square, sq_size, t->next, 0));
}

void	clean_tetri(char *square, size_t sq_size, t_tetri *t)
{
	print_int("clean tetri - sq_size ", sq_size, 0);
	print_char(" - tetri ", t->alpha, 1);

	int i;

	i = -1;
	while (++i < 4)
		square[formula(sq_size, t, i)] = '.';
}

char	*the_mind(char *square, size_t sq_size, t_tetri *t, int offset)
{
	print_int("the mind - sq_size ", sq_size, 0);
	if (t)
		print_char(" - tetri ", t->alpha, 0);
	else
		ft_putendl("\nerror : no tetri");
	print_int(" - offset ", offset, 1);

	if (offset == -1)
	{
		while (square[++offset] != t->alpha)
			++offset;
		clean_tetri(square, sq_size, t);
		if (++offset < ft_strlen(square))
			return (the_mind(square, sq_size, t, offset));
	}
	if (try_place_tetri(square, sq_size, t, offset))
	{
		ft_putendl("the_mind returning place_tetri");
		return (place_tetri(square, sq_size, t, offset));
	}
	if (offset < ft_strlen(square))
	{
		ft_putendl("the_mind returning the_mind");
		return (the_mind(square, sq_size, t->next, 0));
	}
	if (!(t->prev))
		return ("too small");
	ft_putendl("the_mind returning the_mind");
	return (the_mind(square, sq_size, t->prev, -1));
}

/****************************************************************************/

// int		formula(t_tetri *t, int i, size_t sq_size)
// {
// 	return (t->block[i][0] + t->block[i][1] * (sq_size - 4));
// }

// int		try_place_tetri(char *square, int sq_size, t_tetri *t)
// {
// 	int i;
// 	int ok;

// 	i = -1;
// 	ok = 1;
// 	while (++i < 4 && ok)
// 		if (square[formula(t, i, sq_size)] != '.')
// 			ok = 0;
// 	return (ok);
// }

// int		place_tetri(char *square, int sq_size, t_tetri *t, int offset)
// {
// 	int i;

// 	i = -1;
// 	while (++i < 4)
// 		square[formula(t, i, sq_size) + offset] = t->alpha;
// 	return (1);
// }

// char	*clean_tetri(char *square, int sq_size, t_tetri *t, int offset)
// {
// 	int i;

// 	i = -1;
// 	while (++i < 4)
// 		square[formula(t, i, sq_size)] = '.';
// 	if (offset < ft_strlen(square))
// 		return (the_mind(square, sq_size, t, ++offset));
// 	if (t->prev)
// 		if (prev_offset < ft_strlen(square))
// 			return (the_mind(square, sq_size, t->prev, prev_offset));
// 	return ("too small");
// }

// char	*the_mind(char *square, int sq_size, t_tetri *t, int offset)
// {
// 	if (try_place_tetri(square, sq_size, t))
// 		return (0);
// 	if (place_tetri(square, sq_size, t, offset))
// 		return (the_mind(square, sq_size, t->next, 0));
// 	return (clean_tetri(square, sq_size, t, offset));
// }

/****************************************************************************/

// char	*the_old_mind(char *square, t_tetri *t)
// {
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
// 	return (square);
// }

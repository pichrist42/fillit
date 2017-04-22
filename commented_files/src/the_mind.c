/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/22 04:53:07 by pichrist         ###   ########.fr       */
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
	// if (sq_size < 4)
		return (t->block[i][0] + t->block[i][1] * (sq_size + 1));
	// else if (sq_size > 4)
	// 	return (t->block[i][0] + t->block[i][1] * (4 - sq_size));
}

int		try_place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	if (DEBUG_FT)
	{
		ft_putstr("try_place_tetri");
		print_char(" - tetri ", t->alpha, 1);
	}
	if (DEBUG_PLACEMENT)
	{
		print_int(" - sq_size ", sq_size, 0);
		print_int(" - offset ", offset, 1);
	}

	int i;
	int ok;

	i = -1;
	ok = 1;
	if (DEBUG_PLACEMENT)
	{
		print_int("\tsq_size ", sq_size, 1);
		print_int("\toffset ", offset, 1);
	}
	while (++i < 4 && ok)
	{
		if (DEBUG_PLACEMENT)
		{
			ft_putendl("\tnew loop");
			print_int("\t\ti ", i, 1);
			print_int("\t\tx ", t->block[i][0], 1);
			print_int("\t\ty ", t->block[i][1], 1);
			print_char("\t\tchar checked is ", square[formula(sq_size, t, i) + offset], 1);
			print_int("\t\tformula ", formula(sq_size, t, i), 1);
		}
		if (square[formula(sq_size, t, i) + offset] != '.')
			ok = 0;
	}
	if(DEBUG_PLACEMENT)
		print_int("\treturns ", ok, 1);
	return (ok);
}

char	*place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	if (DEBUG_FT)
	{
		ft_putstr("place_tetri");
		print_char(" - tetri ", t->alpha, 1);
	}
	if (DEBUG_PLACEMENT)
	{
		print_int(" - sq_size ", sq_size, 0);
		print_int(" - offset ", offset, 1);
	}
	int i;

	i = -1;
	while (++i < 4)
		square[formula(sq_size, t, i) + offset] = t->alpha;
	if (DEBUG_FT)
		ft_putendl("\tplace_tetri -> the_mind");
	if (DEBUG_SQUARE)
		ft_putendl(square);
	if (t->next)
		return (the_mind(square, sq_size, t->next, 0));
	return (square);
}

void	clean_tetri(char *square, size_t sq_size, t_tetri *t, int offset)
{
	if (DEBUG_FT)
	{
		ft_putstr("clean tetri");
		print_char(" - tetri ", t->alpha, 1);
	}
	if (DEBUG_PLACEMENT)
	{
		print_int(" - sq_size ", sq_size, 0);
	}
	int i;

	i = -1;
	while (++i < 4)
	{
		if (DEBUG_PLACEMENT)
		{
			print_int("i ", i, 0);
			print_int(" - formula ", formula(sq_size, t, i), 0);
			print_char(" - char ", square[formula(sq_size, t, i) + offset], 1);
		}
		square[formula(sq_size, t, i) + offset] = '.';
	}
}

char	*the_mind(char *square, size_t sq_size, t_tetri *t, int offset)
{
	// if (sq_size != 4)
	// 	return ("error");
	if (DEBUG_FT)
	{
		ft_putstr("the_mind");
		print_char(" - tetri ", t->alpha, 0);
		print_int(" - offset ", offset, 1);
	}
	if (DEBUG_PLACEMENT)
	{
		print_int(" - sq_size ", sq_size, 0);
	}

	if (offset == -1)
	{
		if (DEBUG_PLACEMENT)
		{
			// ft_putstr(square);
			print_char("old alpha ", t->alpha, 1);
			print_int("buggy offset ", offset, 1);
			print_char("1st char ", square[offset + 1], 1);
		}
		while (square[++offset] != t->alpha)
			;
		if (DEBUG_PLACEMENT)
			print_int("old offset ", offset, 1);
		if (DEBUG_FT)
			ft_putendl("\tthe_mind cleaning\n");
		if (DEBUG_FT)
		{
			print_char("before cleaning ", t->alpha, 1);
			ft_putendl(square);
		}
		clean_tetri(square, sq_size, t, offset);
		if (DEBUG_FT)
		{
			ft_putendl("after cleaning");
			ft_putendl(square);
		}
		if (++offset < ft_strlen(square))
		{
			if (DEBUG_FT)
				ft_putendl("\tthe_mind -> the_mind - prev char");
			return (the_mind(square, sq_size, t, offset));
		}
	}
	if (DEBUG_FT)
		ft_putendl("\tthe_mind -> try_place_tetri");
	if (try_place_tetri(square, sq_size, t, offset))
	{
		if (DEBUG_FT)
			ft_putendl("\tthe_mind -> place_tetri");
		return (place_tetri(square, sq_size, t, offset));
	}
	if (offset < ft_strlen(square))
	{
		if (DEBUG_FT)
			ft_putendl("\tthe_mind -> the_mind - inc offset");
		return (the_mind(square, sq_size, t, ++offset));
	}
	if (!(t->prev))
		return ("too small");
	if (DEBUG_FT)
		ft_putendl("\tthe_mind -> the_mind - return to prev tetri");
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

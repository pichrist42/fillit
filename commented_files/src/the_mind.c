/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_mind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:00 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/30 19:19:56 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		formula(size_t square_size, t_tetri *t, int i){
	return (t->block[i][0] + t->block[i][1] * (square_size + 1));
}

char	*the_mind(char *square, size_t square_size, t_tetri *t){
	print_int("square_size ", square_size, 1);
	int	block_nb;
	int	offset;
	int found_place;
	int	rollback;
	int i = -1;

	rollback = 0;
	while (1){
		// ft_putstr("plante cette fois ?\n");
		// getchar();
		print_int("loop ", ++i, 1);
		print_char("placing tetri ", t->alpha, 1);
		// clean
		if (rollback){
			print_str(1, "calculating rollback", 1);
			offset = -1;
			while (rollback){
				++offset;
				print_int("\trllbcking with offset ", offset, 1);
				rollback = 0;
				block_nb = -1;
				while (++block_nb < 4 && !rollback)
					if (square[formula(square_size, t, block_nb) + offset] != t->alpha)
						rollback = 1;
			}
			// clean
			block_nb = -1;
			while (square[++block_nb])
				if (square[block_nb] == t->alpha)
					square[block_nb] = '.';
			++offset;
		}else{
			ft_putendl("\toffset reset");
			offset = -1;
		}
		// try_place_tetri
		print_int("\toffset b4 inc ", offset, 1);
		int j = -1;
		int k = -1;
		found_place = 0;
		while (++offset < ft_strlen(square) && !found_place){
			// print_int("j ", ++j, 1);
			block_nb = -1;
			found_place = 1;
			k = -1;
			print_int("\t\ttrying offset ", offset, 1);
			while (++block_nb < 4 && found_place){
				// print_int("k ", ++k, 1);
				if (square[formula(square_size, t, block_nb) + offset] != '.')
					found_place = 0;
				// print_int("found_place ", found_place, 1);
			}
		}
		// place_tetri
		if (found_place)
			print_str(1, "place tetri", 1);
		else
			print_str(1, "no tetri placed", 1);
		if (found_place){
			block_nb = -1;
			--offset;
			print_int("final offset ", offset, 1);
			while (++block_nb < 4)
				square[formula(square_size, t, block_nb) + offset] = t->alpha;
			if (!(t->next)){
				print_str(0, "end", 1);
				return (square);
			}
			rollback = 0;
			t = t->next;
			print_str(1, "tetri placed", 1);
			print_str(0, square, 1);
			// ft_putstr("plante ?\n");
			continue;
		}
		// coudlnt place tetri
		if ((!t->prev)){
			print_str(0, "too small", 1);
			return ("too small");
		}
		rollback = 1;
		t = t->prev;
		print_str(1,"will rllbk", 1);
	}
}

/*
int		formula(size_t sq_size, t_tetri *t, int i)
{
		return (t->block[i][0] + t->block[i][1] * (sq_size + 1));
}

int		try_place_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	int i = -1, ok = 1;
	while (++i < 4 && ok)
	{
		if (square[formula(sq_size, t, i) + offset] != '.')
			ok = 0;
	}
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
	while (square[++i])
		if (square[i] == t->alpha)
			square[i] = '.';
}

int		try_superpose_tetri(char *square, int sq_size, t_tetri *t, int offset)
{
	int i = -1, ok = 1;
	while (++i < 4 && ok)
	{
		if (square[formula(sq_size, t, i) + offset] != t->alpha)
			ok = 0;
	}
	return (ok);
}

char	*the_mind(char *square, size_t sq_size, t_tetri *t, int offset)
{
	if (offset == -1)
	{
		while (!try_superpose_tetri(square, sq_size, t, ++offset))
			;
		clean_tetri(square, sq_size, t, offset);
		if (++offset < ft_strlen(square))
			return (the_mind(square, sq_size, t, offset));
	}
	if (try_place_tetri(square, sq_size, t, offset))
	{
		return (place_tetri(square, sq_size, t, offset));
	}
	if (++offset < ft_strlen(square))
		return (the_mind(square, sq_size, t, offset));
	if (!(t->prev))
		return ("too small");
	return (the_mind(square, sq_size, t->prev, -1));
}
*/
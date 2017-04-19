/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:42:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/18 09:12:03 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	find_prev_t_alpha(t_tetri *t)
{
	if (t->prev)
		return (t->prev->alpha + 1);
	return ('A');
}

void	do_debug_find(int block_read, int i, int j, char alpha)
{
	if (DEBUG_CREATION_DETAILLED)
	{
		print_int("block ", block_read, 0);
		print_int(" - i: ", i, 0);
		print_int(", j: ", j, 0);
		print_char(" - alpha : ", alpha, 1);
	}
}

void	do_debug_read(char *file_content, int i, int j)
{
	if (DEBUG_CREATION_SPECIFIC)
	{
		print_char("", file_content[i + j * 5], 0);
		print_int(" - i: ", i, 0);
		print_int(", j: ", j, 1);
	}
}

t_tetri	*find_tetri(char *file_content, int i, int j, int block_read, t_tetri *first)
{
	t_tetri *t;
	int		off_read;

	off_read = 0;
	if (!(first = create_tetri()))
		return (NULL);
	t = first;
	while (file_content[i + j * 5 + off_read])
	{
		// if (block_read >= 3)
		if (!(j % 4) && j > 0)
		{
			if (DEBUG_CREATION_DETAILLED || DEBUG_CREATION_SPECIFIC)
				ft_putendl("next tetri");
			t->next = create_tetri();
			t->next->prev = t;
			t = t->next;
			block_read = -1;
			off_read += 21;
			i = 0;
			j = 0;
		}
		// do_debug_read(file_content, i, j);
		if (file_content[i + j * 5 + off_read] == '#')
		{
			// t->alpha = find_prev_t_alpha(t);
			t->alpha = ((t->prev) ? t->prev->alpha + 1 : 'A');
			t->block[++block_read][0] = i;
			t->block[block_read][1] = j;
			// do_debug_find(block_read, i, j, t->alpha);
		}
		if (file_content[i + j * 5 + off_read] == '\n')
		{
			if(DEBUG_CREATION_SPECIFIC)
				ft_putendl("reset i");
			i = -1;
			++j;
		}
		++i;
	}
	// return (first);
	return (push_up_tetri(first, first));
}

t_tetri	*push_up_tetri(t_tetri *first, t_tetri *t)
{
	int i;
	int ok;

	i = -1;
	ok = 0;
	while (++i < 4)
		if (t->block[i][1] == 0)
			ok = 1;
	if (!ok)
	{
		i = -1;
		while (++i < 4)
			t->block[i][1] -= 1;
	}
	if (t->next)
		return (push_up_tetri(first, t->next));
	return (first);
}

// 	i = -1;
// 	if (t->block[0][1] > 0)
// 		while (++i < 4)
// 			--t->block[i][1];
// 	if (t->next)
// 		return (push_up_tetri(first, t->next));
// 	return (first);
// }

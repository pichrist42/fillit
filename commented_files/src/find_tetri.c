/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:42:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/22 06:00:49 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*	debug
	*/
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

	/*
*/

void	find_tetri_sub(t_tetri **t, int *block_read, int *off_read)
{
	// ft_putendl("new tetri");
	// printf("actual %p\n", t);
	(*t)->next = create_tetri();
	// printf("next %p\n", t->next);
	(*t)->next->prev = *t;
	// printf("actual %p\n", t->next->prev);
	(*t) = (*t)->next;
	// printf("next %p\n", t);
	*block_read = -1;
	*off_read += 21;
}

void	find_tetri_tri(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

void	find_tetri_quad(int *i, int *j, t_tetri *t, int *block_read)
{
	// printf("writing on %p\n", t);
	t->alpha = ((t->prev) ? t->prev->alpha + 1 : 'A');
	// print_char("alpha ", t->alpha, 1);
	t->block[++(*block_read)][0] = *i;
	// print_int("coord: ", t->block[*block_read][0], 0);
	t->block[*block_read][1] = *j;
	// print_int(";", t->block[*block_read][1], 1);
}

t_tetri	*push_left_tetri(t_tetri *first, t_tetri *t)
{
	int i;
	int again;

	i = -1;
	again = 1;
	while (again)
	{
		if (again > 1)
		{
			i = -1;
			while (++i < 4)
				t->block[i][0] -= 1;
		}
		else
			++again;
		i = -1;
		while (++i < 4)
			if (t->block[i][0] == 0)
				again = 0;
	}
	if (t->next)
		return (push_left_tetri(first, t->next));
	return (first);
}

t_tetri	*push_up_tetri(t_tetri *first, t_tetri *t)
{
	int i;
	int again;

	i = -1;
	again = 1;
	while (again)
	{
		if (again > 1)
		{
			i = -1;
			while (++i < 4)
				t->block[i][1] -= 1;
		}
		else
			++again;
		i = -1;
		while (++i < 4)
			if (t->block[i][1] == 0)
				again = 0;
	}
	if (t->next)
		return (push_up_tetri(first, t->next));
	return (push_left_tetri(first, first));
}

t_tetri	*find_tetri(char *file_content, int i, int j, int block_read)
{
	t_tetri *t;
	t_tetri	*first;
	int		off_read;

	off_read = 0;
	if (!(first = create_tetri()))
		return (NULL);
	t = first;
	// printf("first %p\n", t);
	while (file_content[i + j * 5 + off_read])
	{
		// if (block_read >= 3)
		if (!(j % 4) && j > 0)
		{
			// if (DEBUG_CREATION_DETAILLED || DEBUG_CREATION_SPECIFIC)
			// 	ft_putendl("next tetri");
			t_tetri **u = &t;
			find_tetri_sub(u, &block_read, &off_read);
			find_tetri_tri(&i, &j);
		}
		// do_debug_read(file_content, i, j);
		if (file_content[i + j * 5 + off_read] == '#')
		{
			// t->alpha = find_prev_t_alpha(t);
			find_tetri_quad(&i, &j, t, &block_read);
			// do_debug_find(block_read, i, j, t->alpha);
		}
		if (file_content[i + j * 5 + off_read] == '\n')
		{
			// if(DEBUG_CREATION_SPECIFIC)
			// 	ft_putendl("next line");
			i = -1;
			++j;
		}
		++i;
	}
	// printf("first %p\n", first);
	return (push_up_tetri(first, first));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:42:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/26 04:31:17 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	find_tetri_sub(t_tetri **t, int *block_read, int *off_read)
{
	(*t)->next = create_tetri();
	(*t)->next->prev = *t;
	(*t) = (*t)->next;
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
	t->alpha = ((t->prev) ? t->prev->alpha + 1 : 'A');
	t->block[++(*block_read)][0] = *i;
	t->block[*block_read][1] = *j;
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
	while (file_content[i + j * 5 + off_read])
	{
		if (!(j % 4) && j > 0)
		{
			t_tetri **u = &t;
			find_tetri_sub(u, &block_read, &off_read);
			find_tetri_tri(&i, &j);
		}
		if (file_content[i + j * 5 + off_read] == '#')
			find_tetri_quad(&i, &j, t, &block_read);
		if (file_content[i + j * 5 + off_read] == '\n')
		{
			i = -1;
			++j;
		}
		++i;
	}
	return (push_up_tetri(first, first));
}

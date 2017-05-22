/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:14:31 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/23 00:58:11 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	destroy_tetri(t_tetri *first)
{
	t_tetri *t;

	while (first->next)
	{
		t = first;
		first = first->next;
		destroy_every_tetri(t);
	}
	destroy_every_tetri(first);
}

void	destroy_every_tetri(t_tetri *t)
{
	free(t->block[0]);
	free(t->block);
	free(t);
}

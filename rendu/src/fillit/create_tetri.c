/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:42:06 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/19 17:35:45 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit/fillit.h"

t_tetri	*create_tetri(void)
{
	t_tetri	*new;
	int		i;

	i = 0;
	new = (t_tetri*)malloc(sizeof(t_tetri));
	if (!new)
		return (NULL);
	new->block = (size_t**)malloc(4 * sizeof(size_t*));
	new->block[0] = (size_t*)malloc(4 * 2 * sizeof(size_t));
	while (++i < 4)
		new->block[i] = new->block[i - 1] + 2;
	new->next = (t_tetri*)NULL;
	new->prev = (t_tetri*)NULL;
	new->alpha = 'A';
	return (new);
}

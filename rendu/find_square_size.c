/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:57 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/23 03:56:08 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	find_square_size(char *file_content)
{
	size_t	tetri_nb;
	size_t	i;

	tetri_nb = 0;
	i = -1;
	while (++i < ft_strlen(file_content) - 2)
		if ((file_content[i] == CHAR_SPACE || file_content[i] == CHAR_ELEM) && \
			file_content[i + 1] == CHAR_NL && file_content[i + 2] == CHAR_NL)
			++tetri_nb;
	++tetri_nb;
	i = 2;
	while (i * i < tetri_nb * 4)
		++i;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:57 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 21:22:47 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
	// print_int("tetri nb ", tetri_nb, 1);
	i = 2;
	while (i * i < tetri_nb * 4)
		++i;
	// print_int("size min ", i, 1);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:57 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/13 20:01:45 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit/fillit.h"

size_t	find_square_size(char *file_content)
{
	size_t	tetri_nb;
	size_t	i;

	tetri_nb = 0;
	i = -1;
	while (++i < ft_strlen(file_content) - 2)
		if ((file_content[i] == '.' || file_content[i] == '#') && \
			file_content[i + 1] == '\n' && file_content[i + 2] == '\n')
			++tetri_nb;
	i = 2;
	while (i * i < tetri_nb * 4)
		++i;
	return (i);
}

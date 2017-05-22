/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:36 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 21:22:53 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*gen_square(size_t sq_size)
{
	char	*square;
	int		i;

	if (!(square = ft_strnew((sq_size + 1) * sq_size)))
		return (NULL);
	i = 0;
	while (++i <= (int)((sq_size + 1) * sq_size))
		if (!(i % (sq_size + 1)) && i)
			square[i - 1] = CHAR_NL;
		else
			square[i - 1] = CHAR_SPACE;
	return (square);
}

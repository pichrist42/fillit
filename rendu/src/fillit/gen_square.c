/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:43:36 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 06:29:02 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit/fillit.h"

char	*gen_square(size_t sq_size)
{
	char	*square;
	int		i;

	if (!(square = ft_strnew((sq_size + 1) * sq_size)))
		return (NULL);
	i = 0;
	while (++i <= (sq_size + 1) * sq_size)
		if (!(i % (sq_size + 1)) && i)
			square[i - 1] = '\n';
		else
			square[i - 1] = '.';
	return (square);
}

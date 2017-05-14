/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:44:41 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/13 20:01:35 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit/fillit.h"

void	display_square(char *square)
{
	int i;

	i = -1;
	while (square[++i])
		ft_putchar(square[i]);
}

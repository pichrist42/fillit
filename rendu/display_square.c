/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:44:41 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/23 03:56:09 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_square(char *square)
{
	int i;

	i = -1;
	while (square[++i])
		ft_putchar(square[i]);
}

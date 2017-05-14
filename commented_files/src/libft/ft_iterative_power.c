/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:54:59 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/17 05:16:19 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

int		ft_iterative_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	res = 1;
	while (power--)
		res *= nb;
	return (res);
}

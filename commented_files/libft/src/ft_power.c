/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:54:14 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:32:17 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (!power)
		return (1);
	return (nb * ft_power(nb, --power));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:46:36 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:31:08 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa(int nbr)
{
	char	buf[12];
	int		i;
	int		neg;

	i = 10;
	ft_bzero(buf, 12);
	if (!nbr)
		return (ft_strdup("0"));
	neg = (nbr < 0) ? 1 : 0;
	while (nbr != 0)
	{
		buf[i--] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		buf[i] = '-';
	return (ft_strdup(buf + i + ((!neg) ? 1 : 0)));
}

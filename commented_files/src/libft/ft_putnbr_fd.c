/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:38:01 by pichrist          #+#    #+#             */
/*   Updated: 2016/11/30 18:23:07 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int d;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	d = (unsigned int)n;
	if (d < 10)
		ft_putchar_fd(d + '0', fd);
	else
	{
		ft_putnbr_fd(d / 10, fd);
		ft_putchar_fd(d % 10 + '0', fd);
	}
}

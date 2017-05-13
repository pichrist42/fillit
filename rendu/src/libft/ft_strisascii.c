/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:01:23 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/22 13:10:18 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

int	ft_strisascii(char *str)
{
	str--;
	while (str++)
		if (!ft_isascii(*str))
			return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:05:50 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/22 13:11:13 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

int	ft_strisdigit(char *str)
{
	str--;
	while (str++)
		if (!ft_isdigit(*str))
			return (0);
	return (1);
}

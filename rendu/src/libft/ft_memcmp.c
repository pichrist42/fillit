/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:54:28 by pichrist          #+#    #+#             */
/*   Updated: 2016/11/29 19:10:26 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*p1 = str1;
	const unsigned char	*p2 = str2;
	size_t				i;

	if (n != 0)
	{
		i = 0;
		while (i++ < n)
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
	}
	return (0);
}

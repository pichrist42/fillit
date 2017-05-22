/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:53:32 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:31:59 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char *p = str;
	size_t				i;

	if (n)
	{
		i = 0;
		while (i++ < n)
			if (*p++ == (unsigned char)c)
				return (void *)(p - 1);
	}
	return (0);
}

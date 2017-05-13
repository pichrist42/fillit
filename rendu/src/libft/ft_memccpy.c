/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:50:52 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/14 02:19:07 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc = src;
	size_t				i;

	if (n)
	{
		i = 0;
		pdest = (unsigned char*)dest;
		while (i++ < n)
			if ((*pdest++ = *psrc++) == (unsigned char)c)
				return (pdest);
	}
	return (0);
}

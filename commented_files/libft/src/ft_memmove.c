/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:58:34 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:32:12 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
		while (n--)
			*((char*)dst + n) = *((char*)src + n);
	return (dst);
}

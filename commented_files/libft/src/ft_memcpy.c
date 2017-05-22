/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:49:57 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:32:06 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memcpy(void *v_dst, const void *v_src, size_t length)
{
	char		*dst;
	const char	*src = v_src;

	dst = (char*)v_dst;
	while (length != 0 && dst != src)
	{
		*dst++ = *src++;
		length--;
	}
	return (v_dst);
}

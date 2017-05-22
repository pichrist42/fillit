/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:01:01 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:34:54 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t c_dest;
	size_t c_src;

	c_dest = 0;
	c_src = 0;
	while (dest[c_dest])
		c_dest++;
	while (src[c_src] && c_src < nb)
	{
		dest[c_dest] = src[c_src];
		c_dest++;
		c_src++;
	}
	dest[c_dest] = '\0';
	return (dest);
}

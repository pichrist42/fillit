/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:59:07 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:32:44 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int c_dest;
	int c_src;

	c_dest = 0;
	c_src = 0;
	while (dest[c_dest])
		c_dest++;
	while (src[c_src])
		dest[c_dest++] = src[c_src++];
	dest[c_dest] = '\0';
	return (dest);
}

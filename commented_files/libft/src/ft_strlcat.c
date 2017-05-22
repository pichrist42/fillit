/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:02:32 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:34:40 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (dst[start] && start < size)
		start++;
	if (start < size)
	{
		while (start + i + 1 < size && src[i])
		{
			dst[start + i] = (char)src[i];
			i++;
		}
		dst[start + i] = '\0';
	}
	return (start + ft_strlen((char*)src));
}

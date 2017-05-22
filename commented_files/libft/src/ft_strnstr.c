/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:09:05 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:35:10 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_str(const char *src, const char *find, size_t i, size_t n)
{
	size_t	j;

	j = 0;
	while (src[i] && find[j] && i < n)
	{
		if (src[i] != find[j])
			return (0);
		i++;
		j++;
	}
	if (find[j] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	i;

	i = 0;
	if (find[0] == '\0')
		return ((char*)src);
	while (src[i] && i < len)
	{
		if (src[i] == find[0])
		{
			if (ft_check_str(src, find, i, len) == 1)
				return ((char*)&src[i]);
		}
		i++;
	}
	return (NULL);
}

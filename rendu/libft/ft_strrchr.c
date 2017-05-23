/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:05:54 by pichrist          #+#    #+#             */
/*   Updated: 2016/11/29 19:14:30 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char*)&s[i]);
	while (i > 0)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	return (NULL);
}

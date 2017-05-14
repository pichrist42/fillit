/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:36:43 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/09 21:00:58 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = -1;
	new = NULL;
	if (s)
	{
		if (!(new = ft_strnew(len)))
			return (NULL);
		while (++i < len && s[i])
			new[i] = (char)s[start + i];
		return (new);
	}
	return (NULL);
}

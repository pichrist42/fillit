/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:34:09 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:34:51 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	new = NULL;
	if (s && f)
	{
		if (!(new = (char*)ft_memalloc(ft_strlen(s) + 1)))
			return (NULL);
		i = -1;
		while (++i < ft_strlen(s))
			new[i] = f(i, (char)s[i]);
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:32:38 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 01:11:40 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;
	size_t	len;

	new = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		if ((new = (char*)ft_memalloc(len + 1)) == NULL)
			return (NULL);
		i = -1;
		while (++i < len)
			new[i] = f(s[i]);
	}
	return (new);
}

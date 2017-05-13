/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:40:08 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 03:47:55 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupa(char *s, char *l)
{
	char	*buffer;
	int		i;
	int		p;

	if (s == NULL)
		return (NULL);
	if (l == NULL || ft_strlen(l) == 0)
		return (ft_strdup(s));
	p = ft_strchrp(s, l);
	if (p == 0 || ((buffer = ft_strnew(ft_strlen(s) - (ft_strlen(l) + p))) \
		== NULL))
		return (ft_strdup(s));
	i = p + 1;
	p = 0;
	while (s[i])
	{
		buffer[p] = s[i];
		i++;
		p++;
	}
	return (buffer);
}

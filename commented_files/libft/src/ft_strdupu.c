/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:25:11 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:33:19 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdupu(char *s, char *l)
{
	char	*buffer;
	int		i;
	int		p;

	if (s == NULL)
		return (NULL);
	if (l == NULL || ft_strlen(l) == 0)
		return (ft_strdup(s));
	p = ft_strchrp(s, l);
	if (p == 0 || ((buffer = ft_strnew(p + 1)) == NULL))
		return (ft_strdup(s));
	i = -1;
	while (s[++i] && i < p)
		buffer[i] = s[i];
	return (buffer);
}

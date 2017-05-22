/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:37:39 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:34:35 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		new = ft_strnew(sizeof(*new) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!new)
			return (NULL);
		new = ft_strcat(new, (char*)s1);
		new = ft_strcat(new, (char*)s2);
		return (new);
	}
	if (s1)
		return (ft_strdup(s1));
	if (s2)
		return (ft_strdup(s2));
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:48:58 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 03:48:43 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchrp_do(char *s, char *item, size_t i, size_t j)
{
	size_t mem;

	mem = 0;
	while (s[i])
	{
		if (s[i] == item[j])
		{
			if (!mem)
				mem = i;
			j++;
		}
		else if (mem)
		{
			i = mem;
			mem = 0;
			j = 0;
		}
		if (item[j] == '\0')
			return (i - ft_strlen(item) + 1);
		i++;
	}
	return (0);
}

int			ft_strchrp(char *s, char *item)
{
	if (item == NULL || s == NULL)
		return (0);
	return (ft_strchrp_do(s, item, 0, 0));
}

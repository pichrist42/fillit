/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:40:41 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/09 20:44:02 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_get_length(char const *s)
{
	size_t	blanks;
	size_t	i;

	blanks = 0;
	while (s[blanks] == ' ' || s[blanks] == '\t' || s[blanks] == '\n')
		++blanks;
	if (!s[blanks])
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		--i;
		++blanks;
	}
	return (ft_strlen(s) - blanks);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = NULL;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			++i;
		if (!(new = ft_strnew(ft_get_length(s))))
			return (NULL);
		while (j < ft_get_length(s))
		{
			new[j] = s[i];
			++i;
			++j;
		}
	}
	return (new);
}

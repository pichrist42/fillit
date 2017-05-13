/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:45:05 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/22 13:18:20 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strsplit_getwords(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (!s[i])
			return (words);
		words++;
		while (s[i] != c && s[i])
			++i;
	}
	return (words);
}

static char		*ft_strsplit_cut(char const *s, int c, size_t *start)
{
	size_t	j;
	char	*newword;

	j = *start;
	newword = 0;
	while (s[j] != c && s[j])
		++j;
	newword = ft_strsub(s, *start, j - *start);
	*start = j;
	return (newword);
}

static void		*ft_strsplit_abort(char **tab)
{
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	size;

	if (s)
	{
		i = -1;
		size = ft_strsplit_getwords(s, c);
		tab = (char**)ft_memalloc(sizeof(*tab) * (size + 1));
		if (!tab)
			return (NULL);
		tab[size] = (char*)'\0';
		j = 0;
		while (++i < size)
		{
			while (s[j] == c)
				++j;
			tab[i] = ft_strsplit_cut(s, c, &j);
			if (!tab[i])
				return (ft_strsplit_abort(tab));
		}
		return (tab);
	}
	return (NULL);
}

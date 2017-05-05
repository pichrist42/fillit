/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:45:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/05 14:33:07 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		valid_char(char file_content_char)
{
	char elem;
	char space;
	char rttl;

	elem = PCS_ELEM;
	space = PCS_SPACE;
	rttl = PCS_RTTL;
	if (file_content_char == elem || file_content_char == space || \
		file_content_char == rttl)
		return (1);
	return (0);
}

int		valid_pcs(char *pcs)
{
	int i;
	int dot;
	int elem;
	int line;
	int	link;

	i = 0;
	dot = 0;
	elem = 0;
	line = 0;
	link = 0;
	while (i < 20)
	{	
		if (!(valid_char(pcs[i])))
			return (0);
		if (pcs[i] == PCS_ELEM)
		{
			if (pcs[i] == pcs[i - 5])
				++link;
			if (pcs[i] == pcs[i - 1])
				++link;
			if (pcs[i] == pcs[i + 1])
				++link;
			if (pcs[i] == pcs[i + 5])
				++link;
			++elem;
		}
		else if (pcs[i] == PCS_SPACE)
			++dot;
		if (pcs[i] == PCS_RTTL)
		{
			if (pcs[i - 2] == PCS_RTTL || (pcs[i - 2] != PCS_SPACE && pcs[i - 2] != PCS_ELEM))
				return (0);
			++line;
		}
		++i;
	}
	if ((link != 6 && link != 8) || dot != 12 || elem != 4 || (line < 3 && line > 6))
		return (0);
	if (i < 20 && i > 21)
		return (0);
	return (1);
}

int		parse_file(char *file_content)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (file_content[i])
	{
		if (i != 0 && !(i % 21))
		{
			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 21))))
				return (0);
			++j;
		}
		else if (i != 0 && !(file_content[i + 1]))
		{
			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 21))))
				return (0);
		}
		++i;
	}
	if (!file_content[i])
	{
		if (file_content[i - 1] == PCS_RTTL && file_content[i - 2] == PCS_RTTL)
			return (0);
	}
	return (1);
}
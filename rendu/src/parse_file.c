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

int		parse_file(char *file_content)
{
	int i;
	int j;

	i = -1;
	j = 0;
	
	while (file_content[++i])
		if (i != 0 && !(i % 21))
		{
			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 21))))
				return (0);
			++j;
		}
		else if (i != 0 && !(file_content[i + 1]))
			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 21))))
				return (0);
	if (!file_content[i])
		if (file_content[i - 1] == '\n' && file_content[i - 2] == '\n')
			return (0);
	return (1);
}

int		valid_pcs(char *pcs)
{
	int i;
	int dot;
	int line;
	int	link;

	i = -1;
	dot = 0;
	line = 0;
	link = 0;
	while (++i < 20)
	{	
		if (!valid_pcs_sub(pcs, i, &link, &dot))
			return (0);
		if (pcs[i] == '\n')
		{
			if (pcs[i - 2] == '\n' || (pcs[i - 2] != '.' && pcs[i - 2] != '#'))
				return (0);
			++line;
		}
	}
	if ((link != 6 && link != 8) || dot != 12 || (line < 3 && line > 6))
		return (0);
	return (1);
}

int		valid_pcs_sub(char *pcs, int i, int *link, int *dot)
{
	if (!(valid_char(pcs[i])))
		return (0);
	if (pcs[i] == '#')
	{
		if (pcs[i] == pcs[i - 5])
			++*link;
		if (pcs[i] == pcs[i - 1])
			++*link;
		if (pcs[i] == pcs[i + 1])
			++*link;
		if (pcs[i] == pcs[i + 5])
			++*link;
	}
	else if (pcs[i] == '.')
		++*dot;
	return (1);
}

int		valid_char(char to_check)
{
	char elem;
	char space;
	char rttl;

	elem = '#';
	space = '.';
	rttl = '\n';
	if (to_check == elem || to_check == space || to_check == rttl)
		return (1);
	return (0);
}

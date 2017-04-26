/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:45:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/26 23:12:10 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		valid_char(char file_content_char)
{
	char elem;
	char space;
	char rttl;

	elem = '#';
	space = '.';
	rttl = '\n';
	if (file_content_char == elem || file_content_char == space
			|| file_content_char == rttl)
		return (1);
	return (0);
}

int		valid_pcs(char *pcs)
{
	int i;
	int dot;
	int elem;
	int line;

	i = 0;
	dot = 0;
	elem = 0;
	line = 0;
	while (i < 22)
	{
		//Check validite du caractere
		if (!(valid_char(pcs[i])))
			return (0);
		//Check pour le caractere pcs
		if (pcs[i] == '#')
		{
			//Check qu'il touche au moins un autre caractere pcs
			if ((pcs[i] == pcs[i - 5]) || (pcs[i] == pcs[i - 1])
				|| (pcs[i] == pcs[i + 1]) || (pcs[i] == pcs[i + 5]))
			{
				//ft_putchar(i);
				//ft_putchar('\n');
				//ft_putchar(pcs[i - 5]);
				//ft_putchar('\n');
				//ft_putchar(pcs[i - 1]);
				//ft_putchar('\n');
				//ft_putchar(pcs[i + 1]);
				//ft_putchar('\n');
				//ft_putchar(pcs[i + 5]);
				//ft_putchar('\n');
				elem++;
			}
			else
			{
				//ft_putstr("Les pieces ne se touchent pas");
				return (0);
			}
		}
		//Check espace vide
		if (pcs[i] == '.')
			dot++;
		//Check des retours a la ligne tout les 5 chars
		if ((i != 0 && !(i % 5)) && pcs[i] == '\n')
		{
			//ft_putstr("retour a la ligne");
			line++;
		}
		else
			return (0);
		i++;
	}
	if (dot != 12 || elem != 4 || (line < 3 && line > 6))
	{
		//ft_putstr("le compte est pas bon");
		return (0);
	}
	return (1);
}

int		parse_file(char *file_content)
{
	int i;
	int j;

	i = 0;
	j = 0;
	return (0);
	while (file_content[i])
	{
		// Si on a read le contenu d'une piece, on l'envoie a la fonction check pcs
		if (i != 0 && !(i % 21))
		{
			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 21))))
			{
				//ft_putstr("\ncheckpcs invalide");
				return (0);
			}
			j++;
		}
		// RUSTINE POUR FORCER LE CHECK DE LA DERNIERE PIECE
		else if (i != 0 && !(file_content[i + 1]))
		{
			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 20))))
			{
				//ft_putstr("\nchecklastpcs invalide");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

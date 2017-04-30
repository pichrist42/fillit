/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:45:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/30 22:50:48 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// int		valid_char(char file_content_char)
// {
// 	char elem;
// 	char space;
// 	char rttl;

// 	elem = '#';
// 	space = '.';
// 	rttl = '\n';
// 	if (file_content_char == elem || file_content_char == space || \
// 		file_content_char == rttl)
// 		return (1);
// 	return (0);
// }

// int		valid_pcs(char *pcs)
// {
// 	int i;
// 	int dot;
// 	int elem;
// 	int line;
// 	int	link;

// 	i = 0;
// 	dot = 0;
// 	elem = 0;
// 	line = 0;
// 	link = 0;
// 	// if (ft_strlen(pcs) <= 19)
// 	// 	return (0);
// 	while (i < 20)
// 	{
// 		//Check validite du caractere		
// 		if (!(valid_char(pcs[i])))
// 		{
// 			//ft_putstr("char is not valid");
// 			if (DEBUG_PARSE){
// 				print_str(0, "char : ", 0);
// 				if (pcs[i] == ' ')
// 					ft_putstr("space");
// 				else if (pcs[i] == '\n')
// 					ft_putstr("\\n");
// 				else if (pcs[i] == 0)
// 					ft_putstr("null");
// 				else{
// 					ft_putchar(pcs[i]);
// 					ft_putnbr(pcs[i]);
// 				}
// 				print_int("\ni ", i, 1);
// 				ft_putendl("error 4");
// 			}
// 			return (0);
// 		}
// 		//Check pour le caractere pcs
// 		if (pcs[i] == '#')
// 		{
// 			//Check qu'il touche au moins un autre caractere pcs
// 			if (pcs[i] == pcs[i - 5])
// 				++link;
// 			if (pcs[i] == pcs[i - 1])
// 				++link;
// 			if (pcs[i] == pcs[i + 1])
// 				++link;
// 			if (pcs[i] == pcs[i + 5])
// 				++link;
// 			++elem;
// 		}
// 		//Check espace vide
// 		else if (pcs[i] == '.')
// 			++dot;
// 		//Check des retours a la ligne tout les 5 chars
// 		if (i != 0 && !((i + 1) % 5) && pcs[i] == '\n')
// 		{
// 			//ft_putstr("retour a la ligne");
// 			++line;
// 		}
// 		//ft_putstr("i++;\n");
// 		++i;
// 	}
// 	if ((link != 6 && link != 8) || dot != 12 || elem != 4 || (line < 3 && line > 6))
// 	{
// 		if (DEBUG_COUNT){
// 			print_str(0, "le compte est pas bon", 1);
// 			print_int("link ", link, 0);
// 			print_int(" - dot ", dot, 0);
// 			print_int(" - elem ", elem, 0);
// 			print_int(" - line ", line, 1);
// 		}
// 		if (DEBUG_PARSE)
// 			ft_putendl("error 3");
// 		return (0);
// 	}
// 	if (i < 20 && i > 21)
// 	{
// 		print_str(0, "pas le bon nb de char dans la piece", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int		parse_file(char *file_content)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
	
// 	while (file_content[i])
// 	{
// 		// Si on a read le contenu d'une piece, on l'envoie a la fonction check pcs
// 		if (i != 0 && !(i % 21))
// 		{
// 			// print_int("tetri ", j, 1);
// 			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 21))))
// 				return (0);
// 			++j;
// 		}
// 		// RUSTINE POUR FORCER LE CHECK DE LA DERNIERE PIECE
// 		else if (i != 0 && !(file_content[i + 1]))
// 		{
// 			if (!(valid_pcs(ft_strsub(file_content, (j * 21), 20)))){
// 				if (DEBUG_PARSE)
// 					ft_putendl("error 2");
// 				return (0);
// 			}
// 		}
// 		++i;
// 	}
// 	return (1);
// }

int		parse_file(char *file)
{
	int i = -1;
	int nb_tetri = 0;
	int link = 0;
	int line = 0;
	while (file[++i])
	{
		if (file[i] == '#'){
			++nb_tetri;
			if (file[i] == file[i - 5])
				++link;
			if (file[i] == file[i - 1])
				++link;
			if (file[i] == file[i + 1])
				++link;
			if (file[i] == file[i + 5])
				++link;
		}else if (file[i] == '\n'){
			if (file[i - 1] == '.' || file[i - 1] == '#'){
				if (i % 5 != 0){
					ft_putendl("error 1");
					return (0);
				}
				++line;
				// print_int("", i, 1);
			}else if (file[i - 2] != '.' && file[i - 1] != '\n'){
				ft_putendl("error 2");
				return (0);
			}
		}else if (file[i] != '.'){
			ft_putendl("error 3");
			return (0);
		}

		// if (!(i % 21)){
		// 	ft_putendl("error 4");
		// 	return (0);
		/*}else */if ((link != 6 && link != 8)){
			print_int("error 5 : ", link, 0);
			print_int(" - i ", i, 1);
			return 0;
		}else if (nb_tetri != 4){
			ft_putendl("error 6");
			return 0;
		}else if (line != 4){
			ft_putendl("error 7");
			return 0;
		}
		link = 0;
		nb_tetri = 0;
	}
	print_int("i ", i, 1);
	return (1);
}

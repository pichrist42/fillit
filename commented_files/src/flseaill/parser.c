/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 20:10:01 by flseaill          #+#    #+#             */
/*   Updated: 2017/04/16 20:10:03 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_readfile(char *str)
{
	int		fd;
	int		i;
	int		pcsnbr;
	int		buffer;
	char	c;
	char	*pcs;

	i = 0;

	buffer = 21;
	// Compteur du nombre de pieces.
	pcsnbr = 0;

	// Ouverture du Fichier.
	fd = open(str, O_RDONLY);
	
	// Verif de la validite du fd + Allocation du stockage de la piece.
	if (fd == -1 || (!(pcs = malloc(sizeof(char) * buffer + 1))))
		
		// Erreur lors de l'execution.
		return (0);
	
	// Lecture
	while (read(fd, &c, 1) > 0)
	{
		if (i == buffer)
		{
			pcs[i] = '\0';

			// Enregistrement de la piece.
			//ft_savepcs(pcs, ++pcsnbr);
			ft_putstr(pcs);
			++pcsnbr;
			// Reset pour piece suivante.
			i = 0;
		}

		// Enregistrement de la piece.
		pcs[i] = c;
		i++;
	}
	pcs[i] = '\0';

	// Enregistrement de la derniere piece.
	//ft_savepcs(pcs, ++pcsnbr);
	ft_putstr(pcs);
	++pcsnbr;

	printf("\n%d\n", pcsnbr);

	// Fermeture du fichier. + free de pcs.
	close(fd);
	free(pcs);
	
	// La fonction s'est bien execute.
	return (1);
}

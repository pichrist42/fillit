/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 22:10:19 by flseaill          #+#    #+#             */
/*   Updated: 2017/04/14 22:13:08 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_readfile(char *str);

int	main(int argc, char *argv[])
{
	// Il manque des arguments.
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	
	// Il y a trop d'arguments.
	else if (argc < 2)
	ft_putstr("File name missing.\n");
	
	// Si le nombre de parametres est valide.
	else if (argc == 2)
	{
		ft_readfile(argv[1]);
	}
	// FIN
	return (0);
}

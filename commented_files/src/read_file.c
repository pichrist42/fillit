/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:44:14 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/30 21:16:34 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_putendl_mod(char *str, int i){
	ft_putstr("reading : ");
	while (i-- > 0){
		if (str[i] == ' ')
			ft_putstr("space");	
		else if (str[i] == 0)
			ft_putstr("null");
		else if (str[i] == '\n')
			ft_putstr("\\n");
		else if (str[i] == '.')
			ft_putchar(str[i]);
		else if (str[i] == '#')
			ft_putchar(str[i]);
		else if (!ft_isalpha(str[i])){
			ft_putnbr(str[i]);
			ft_putchar(' ');
		}
		else{
			ft_putchar(str[i]);
		}
	}
	ft_putchar('\n');
}

char	*read_file(char *str)
{
	int		fd;
	int		ret;
	char	*buffer;

	fd = open(str, O_RDONLY);
	str = "";
	if (!(buffer = (char*)malloc(21)))
		return (NULL);
	while ((ret = read(fd, buffer, 21))){
		ft_putendl_mod(buffer, ret);
		str = ft_strjoin(str, buffer);
	}
	fd = -1;
	if (!ft_strlen(str))
		return ("file empty");
	while (str[++fd])
		if (!str[fd])
			ft_putstr("\0");
	str[fd] = '\0';
	return (str);
}

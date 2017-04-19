/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:44:14 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 06:51:49 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*read_file(char *str)
{
	int		fd;
	char	*buffer;

	fd = open(str, O_RDONLY);
	str = "";
	if (!(buffer = (char*)malloc(1)))
		return (NULL);
	while (read(fd, buffer, 1))
		str = ft_strjoin(str, buffer);
	fd = -1;
	while (str[++fd])
		if (!str[fd])
			ft_putstr("\0");
	str[fd] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:44:14 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/30 21:55:53 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*read_file(char *str)
{
	int		fd;
	int		ret;
	char	*buffer;

	fd = open(str, O_RDONLY);
	str = "";
	if (!(buffer = (char*)malloc(1)))
		return (NULL);
	while ((ret = read(fd, buffer, 1))){
		str = ft_strjoin(str, buffer);
	}
	fd = -1;
	if (!ft_strlen(str))
		return ("file empty");
	while (str[++fd])
		;
	str[fd] = '\0';
	return (str);
}

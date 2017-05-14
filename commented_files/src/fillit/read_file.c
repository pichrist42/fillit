/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:44:14 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/14 19:33:29 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fillit/fillit.h"

char	*read_file(char *str)
{
	int		fd;
	int		ret;
	char	*buffer;

	fd = open(str, O_RDONLY);
	str = "";
	if (!(buffer = (char*)malloc(1)) || fd == -1 || open(str, O_DIRECTORY) > 0)
		return (NULL);
	while ((ret = read(fd, buffer, 1)))
		str = ft_strjoin(str, buffer);
	fd = -1;
	if (!ft_strlen(str))
		return ("file empty");
	while (str[++fd])
		;
	str[fd] = '\0';
	return (str);
}

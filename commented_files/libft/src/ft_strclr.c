/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:30:06 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:32:52 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strclr(char *s)
{
	int		i;

	if (s)
		i = ft_strlen(s);
	else
		i = -1;
	while (i >= 0)
	{
		s[i] = '\0';
		i--;
	}
}

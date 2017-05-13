/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:23:46 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 03:16:33 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

char	*ft_strdup(const char *s)
{
	char *d;

	if (!(d = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:07:54 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 03:30:28 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

size_t	ft_strlen(const char *str)
{
	const char *c;

	c = str;
	while (*c)
		c++;
	return (c - str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:49:24 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/17 05:11:02 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *c;

	c = (char*)s;
	while (n--)
		c[n] = '\0';
}

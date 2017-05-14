/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:55:22 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/17 05:20:04 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

void	*ft_memalloc(size_t size)
{
	void *area;

	if ((area = malloc(size)) == NULL)
		return (NULL);
	else
		ft_bzero(area, size);
	return ((void*)area);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:27:54 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 01:15:12 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)ft_memalloc(size + 1)))
		return (NULL);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:47:30 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:32:14 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char *d;

	if (n)
	{
		d = (char*)str;
		while (n > 0)
		{
			n--;
			*d = c;
			d++;
		}
	}
	return (str);
}

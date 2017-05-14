/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:15:28 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/17 05:18:39 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

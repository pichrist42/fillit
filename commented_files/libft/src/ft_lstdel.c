/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:24:09 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:31:17 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			next = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = next;
		}
		*alst = NULL;
	}
}

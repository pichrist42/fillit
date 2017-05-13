/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:24:09 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/14 01:37:17 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstc;
	t_list	*lsto;

	if (lst)
	{
		if ((lstc = f(ft_lstnew(lst->content, lst->content_size))) == NULL)
			return (NULL);
		lsto = lstc;
		while (lst->next != NULL)
		{
			lst = lst->next;
			lstc->next = f(ft_lstnew(lst->content, lst->content_size));
			if (lstc == NULL)
				return (NULL);
			lstc = lstc->next;
		}
		return (lsto);
	}
	return (NULL);
}

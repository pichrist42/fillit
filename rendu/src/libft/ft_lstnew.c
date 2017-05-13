/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:24:09 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/14 01:37:31 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)ft_memalloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = (void*)NULL;
		content_size = (size_t)0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (!new->content)
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = (t_list*)NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 03:43:46 by malberte          #+#    #+#             */
/*   Updated: 2018/04/21 22:38:33 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = ft_memalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->content = ft_memalloc(content_size);
	if (new->content == NULL)
	{
		ft_memdel((void**)&new);
		return (NULL);
	}
	if (content)
	{
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	return (new);
}

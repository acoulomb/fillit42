/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 04:59:18 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 21:03:34 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(const t_list *link)
{
	t_list *new;

	if (link == NULL)
		return (NULL);
	new = ft_lstnew(link->content, link->content_size);
	if (new == NULL)
		return (NULL);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 04:50:14 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 21:03:51 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstqueue(t_list **alst, t_list *new)
{
	if (alst)
	{
		while (*alst)
			alst = &(*alst)->next;
		*alst = new;
	}
}

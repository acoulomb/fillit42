/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 13:57:24 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:35:28 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"

/*
** These functions are used in the testing process to put tetriminos.
*/

void	poscpy(t_pos dst, t_cpos src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}

void	posinit(t_pos dst, int x, int y)
{
	dst[0] = x;
	dst[1] = y;
}

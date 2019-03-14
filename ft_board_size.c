/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:39:01 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:48:16 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_board.h"

/*
** This function computes the minimum square in which the given tetriminos
** could fit. The return value is the size of a side (e.g. 3 for a 3x3 square).
*/

int		ft_board_size(int nb_tetrimino)
{
	int board_size;
	int i;

	board_size = nb_tetrimino * NB_BLOCKS;
	if (board_size <= 0)
		return (0);
	i = 1;
	while (board_size >= (i * i))
	{
		if (board_size == (i * i))
			return (i);
		i++;
	}
	return (i);
}

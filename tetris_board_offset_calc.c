/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_board_offset_calc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:27:57 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:45:11 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_board.h"

/*
** These functions are used to compute and apply the offset on the tetriminos.
*/

void	calc_offset(int offset[2], const int pos[2], const t_blocks layout)
{
	offset[HEIGHT] = pos[HEIGHT] - layout[HEIGHEST_BLOCK][HEIGHT];
	offset[WIDTH] = pos[WIDTH] - layout[HEIGHEST_BLOCK][WIDTH];
}

void	apply_offset(t_blocks result, const t_blocks layout, const int pos[2],
					const int offset[2])
{
	int block;

	result[HEIGHEST_BLOCK][HEIGHT] = pos[HEIGHT];
	result[HEIGHEST_BLOCK][WIDTH] = pos[WIDTH];
	block = 1;
	while (block < NB_BLOCKS)
	{
		result[block][HEIGHT] = layout[block][HEIGHT] + offset[HEIGHT];
		result[block][WIDTH] = layout[block][WIDTH] + offset[WIDTH];
		++block;
	}
}

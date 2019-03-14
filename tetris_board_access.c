/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_board_access.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:25:34 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:44:34 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_board.h"

/*
** Checks if the position tested is in the square.
*/

int		is_pos_inside(const int pos[2], int square_size)
{
	if (pos[HEIGHT] >= 0 && pos[HEIGHT] < square_size
		&& pos[WIDTH] >= 0 && pos[WIDTH] < square_size)
		return (1);
	return (0);
}

/*
** Checks if the position tested is in the square.
*/

int		is_square_available(const t_tetris_board *board, int pos[2])
{
	return (board->board[pos[HEIGHT]][pos[WIDTH]]);
}

/*
** Sets 1 if the square is available. Else 0.
*/

void	lock_square(t_tetris_board *board, const int pos[2], int lock_state)
{
	board->board[pos[HEIGHT]][pos[WIDTH]] = lock_state;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:02:29 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:52:51 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_board.h"
#include "position.h"

/*
** This function fills the test board with a tetrimino when it fits a specified
** square, block per block. Returns 1 if it went well.
*/

int		ft_fill_tetrimino(t_tetris_board *board, int pos[2], t_blocks layout)
{
	int block;
	int fill_pos[NB_BLOCKS][2];
	int offset[2];

	if (pos[WIDTH] == -1)
		return (0);
	calc_offset(offset, pos, layout);
	poscpy(fill_pos[HEIGHEST_BLOCK], pos);
	block = 1;
	while (block < NB_BLOCKS)
	{
		fill_pos[block][HEIGHT] = layout[block][HEIGHT] + offset[HEIGHT];
		fill_pos[block][WIDTH] = layout[block][WIDTH] + offset[WIDTH];
		if (!(is_pos_inside(fill_pos[block], board->size)
			&& is_square_available(board, fill_pos[block])))
			return (0);
		++block;
	}
	block = 0;
	while (block < NB_BLOCKS)
	{
		lock_square(board, fill_pos[block], UNAVAILABLE_SQUARE);
		++block;
	}
	return (1);
}

/*
** This function takes out a tetrimino from the test board.
*/

void	ft_unblock_tetrimino(t_tetris_board *board, const int pos[2],
								const int layout[NB_BLOCKS][2])
{
	int			block;
	t_blocks	unblock_pos;
	int			offset[2];

	if (pos[WIDTH] != -1)
	{
		calc_offset(offset, pos, layout);
		apply_offset(unblock_pos, layout, pos, offset);
		block = 0;
		while (block < NB_BLOCKS)
		{
			lock_square(board, unblock_pos[block], AVAILABLE_SQUARE);
			++block;
		}
	}
}

/*
** This function computes the next available square for a given tetrimino,
** according to the test board at this moment. If the tetrimino fits, the board
** is filled (return 1). Else, it returns 0.
*/

int		ft_next_available_square(int next_pos[2],
								t_tetrimino *tetrimino,
								t_tetris_board *board)
{
	int h;
	int w;

	if (next_pos == NULL || tetrimino == NULL || board == NULL)
		return (0);
	posinit(next_pos, 0, -1);
	h = tetrimino->pos[HEIGHT];
	w = tetrimino->pos[WIDTH] + 1;
	while (h < board->size)
	{
		while (w < board->size)
		{
			if (board->board[h][w] == AVAILABLE_SQUARE)
			{
				posinit(next_pos, h, w);
				if (ft_fill_tetrimino(board, next_pos, \
					tetrimino->pattern->blocks_pos))
					return (1);
			}
			++w;
		}
		++h;
		w = 0;
	}
	return (0);
}

/*
** Thanks to an iterative pile algorythm, this function places each tetrimino
** in the highest position on the left, in the given order. If at one point,
** it can't put the next tetrimino, it moves the previous one to it's next
** available square. If all the possibilities have been tested and no solution
** found, the global board size increases.
*/

int		ft_solve_fillit(t_tetris_board *board)
{
	int		n;
	t_pos	next_pos;

	n = 0;
	while (n > -1)
	{
		if (ft_next_available_square(next_pos, board->tetriminos[n], board))
		{
			poscpy(board->tetriminos[n]->pos, next_pos);
			++n;
		}
		else
		{
			posinit(board->tetriminos[n]->pos, 0, -1);
			if (--n != -1)
				ft_unblock_tetrimino(board, board->tetriminos[n]->pos, \
							board->tetriminos[n]->pattern->blocks_pos);
		}
		if (n == board->nb_tetrimino)
			return (1);
	}
	board->size++;
	if (ft_solve_fillit(board))
		return (1);
	return (0);
}

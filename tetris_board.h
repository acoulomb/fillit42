/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_board.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:14:46 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:52:52 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_BOARD_H
# define TETRIS_BOARD_H

# include "tetrimino.h"

# define UNAVAILABLE_SQUARE 0
# define AVAILABLE_SQUARE 1

/*
** The t_tetris_board structure stores the board in which the program solves
** the tetris, the size of the square the program is trying to put the
** tetriminos in, the tetriminos given by the file and their number.
*/

typedef struct	s_tetris_board
{
	char		**board;
	int			size;
	t_tetrimino	*tetriminos[MAX_TETRIMINOS];
	int			nb_tetrimino;
}				t_tetris_board;

void			ft_init_board(t_tetris_board *board);
void			ft_free_tetris_board(t_tetris_board *tetris);
int				ft_fill_tetrimino(t_tetris_board *board,
						int pos[2],
						t_blocks layout);

void			ft_unblock_tetrimino(t_tetris_board *board,
							const int pos[2],
							const int layout[NB_BLOCKS][2]);

int				ft_next_available_square(int next_pos[2],
								t_tetrimino *tetrimino,
								t_tetris_board *board);

int				ft_solve_fillit(t_tetris_board *board);
void			ft_print_solution(const t_tetris_board *board);
int				ft_board_size(int nb_tetrimino);
void			ft_free_solution(char **solution);
void			calc_offset(int offset[2],
							const int pos[2],
							const t_blocks layout);

void			apply_offset(t_blocks result,
							const t_blocks layout,
							const int pos[2],
							const int offset[2]);

int				is_pos_inside(const int pos[2], int square_size);
int				is_square_available(const t_tetris_board *board, int pos[2]);
void			lock_square(t_tetris_board *board,
							const int pos[2],
							int lock_state);

#endif

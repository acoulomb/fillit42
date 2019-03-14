/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:56:59 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetris_board.h"
#include "tetri_lib.h"
#include <stdlib.h>
#include "clean.h"

t_tetrimino_pattern **g_patterns;

static void	ft_usage(int ac)
{
	if (ac == 1 || ac > 2)
	{
		ft_putstr("usage:\t./fillit source_file\n");
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_tetris_board	board;
	char			str[TETRI_LIB_BUF_SIZE];
	char			buf[BUF_SIZE];

	ft_usage(argc);
	g_clean.tetris = &board;
	g_clean.g_patterns = g_patterns;
	ft_tetri_lib(str);
	g_patterns = ft_read_patterns(str);
	if (!ft_tetri_to_str(buf, BUF_SIZE, argv[1]))
		ft_exit();
	if (!ft_read_tetriminos(board.tetriminos, &(board.nb_tetrimino), buf))
		ft_exit();
	ft_init_board(&board);
	if (!ft_solve_fillit(&board))
		ft_exit();
	ft_print_solution(&board);
	ft_free_tetris_board(&board);
	return (0);
}

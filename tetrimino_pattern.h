/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_pattern.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:02:13 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:40:26 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_PATTERN_H
# define TETRIMINO_PATTERN_H

# define HEIGHT 0
# define WIDTH 1
# define HEIGHEST_BLOCK 0
# define LEFTMOST_BLOCK 1
# define NB_BLOCKS 4
# define BLOCK_CHARACTER '#'
# define BUF_SIZE 546

typedef struct				s_tetrimino_pattern
{
	int		blocks_pos[NB_BLOCKS][2];
	char	name[3];
	int		dim[2];
}							t_tetrimino_pattern;

typedef int	t_blocks[NB_BLOCKS][2];

extern t_tetrimino_pattern	**g_patterns;

/*
** g_patterns is the global that contains the 19 standard t_tetrimino_pattern.
** It is used each time the program reads a tetrimino, in order to recognise
** the pattern.
*/

t_tetrimino_pattern			**ft_read_patterns(const char *str);
void						ft_coords_to_layout(t_blocks blocks_coords);
t_tetrimino_pattern			*ft_pattern_recognition(t_blocks pos);
void						ft_free_patterns(t_tetrimino_pattern **g_patterns);
void						ft_make_layout(t_blocks layout, int offset[2]);

#endif

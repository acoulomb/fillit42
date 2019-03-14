/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:43:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:51:50 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

# include <string.h>
# include "tetrimino_pattern.h"
# define MAX_TETRIMINOS 26
# define TETRIMINO_MAP_SIZE 20
# define TETRIMINO_INPUT_SIZE 20

typedef struct	s_tetrimino
{
	t_tetrimino_pattern *pattern;
	int					pos[2];
}				t_tetrimino;

/*
** The t_tetrimino structure stores for each tetrimino given, the information
** associated to its pattern and his position at the moment on the grid.
*/

int				ft_tetri_to_str(char *buf, size_t buf_size, char *filename);
int				ft_read_tetriminos(t_tetrimino **tetri, int *nb_tetri,
									const char *buf);
void			ft_free_tetri(t_tetrimino **tetri, int *nb_tetri);

#endif

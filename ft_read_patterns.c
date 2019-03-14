/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_patterns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:49:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:38:29 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "tetrimino_pattern.h"
#include "clean.h"

/*
** This function allocates memory to store the patterns.
*/

static t_tetrimino_pattern	**init_patterns_tab(unsigned int nb_patterns)
{
	t_tetrimino_pattern	**patterns;
	size_t				tab_size;

	tab_size = sizeof(t_tetrimino_pattern *) * (nb_patterns + 1);
	patterns = (t_tetrimino_pattern **)ft_memalloc(tab_size);
	if (patterns == NULL)
		ft_exit();
	return (patterns);
}

/*
** This function allocates memory to read each pattern.
*/

static t_tetrimino_pattern	*init_pattern(void)
{
	t_tetrimino_pattern *tetri;

	tetri = (t_tetrimino_pattern *)ft_memalloc(sizeof(t_tetrimino_pattern));
	if (tetri == NULL)
		ft_exit();
	return (tetri);
}

/*
** This function reads and stores the absolute coordinates of each patterns.
*/

static int					read_pattern_layout(t_tetrimino_pattern *pat, \
												const char *src)
{
	int h;
	int w;
	int nb_block;
	int src_i;

	nb_block = 0;
	h = -1;
	src_i = 0;
	while (++h < pat->dim[HEIGHT])
	{
		w = -1;
		while (++w < pat->dim[WIDTH])
		{
			if (src[src_i] == '#')
			{
				pat->blocks_pos[nb_block][HEIGHT] = h;
				pat->blocks_pos[nb_block][WIDTH] = w;
				nb_block++;
			}
			src_i++;
		}
		src_i++;
	}
	return (src_i);
}

/*
** This function reads the string that contains the 'tetrimino library'
** and stores the patterns.
*/

t_tetrimino_pattern			**ft_read_patterns(const char *str)
{
	t_tetrimino_pattern	**patterns;
	int					k;
	int					nb_pat;

	k = 0;
	nb_pat = ft_atoi(str);
	k += 3;
	patterns = init_patterns_tab(nb_pat);
	while (str[k])
	{
		--nb_pat;
		patterns[nb_pat] = init_pattern();
		ft_strncpy(patterns[nb_pat]->name, str + k, 2);
		k += 3;
		patterns[nb_pat]->dim[HEIGHT] = ft_atoi(str + k);
		k += 2;
		patterns[nb_pat]->dim[WIDTH] = ft_atoi(str + k);
		k += 2;
		k += read_pattern_layout(patterns[nb_pat], str + k);
	}
	return (patterns);
}

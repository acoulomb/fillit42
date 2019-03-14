/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:39:31 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:51:31 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetrimino.h"
#include "clean.h"

/*
** This function reads one line in the tetrimino and saves the coordinates
** of the blocks read. It also checks if the tetrimino declaration is valid
** (4 blocks,# and .).
*/

static char		*read_line(t_blocks pos, int *nb_blk, const char *buf, int h)
{
	int w;

	w = 0;
	while (w < NB_BLOCKS && buf[w])
	{
		if (buf[w] == '#')
		{
			if (*nb_blk < NB_BLOCKS)
			{
				pos[*nb_blk][HEIGHT] = h;
				pos[*nb_blk][WIDTH] = w;
			}
			else
				ft_exit();
			++*nb_blk;
		}
		else if (buf[w] != '.')
			ft_exit();
		++w;
	}
	if (w < NB_BLOCKS)
		ft_exit();
	return ((char *)(buf + w));
}

/*
** This function reads 4lines in the file and returns the tetriminos in a
** string.
*/

static char		*read_4lines(const char *buf, t_blocks pos)
{
	int					nb_blocks;
	int					h;

	nb_blocks = 0;
	h = 0;
	while (*buf && h < 3)
	{
		buf = read_line(pos, &nb_blocks, buf, h);
		if (buf == NULL)
			ft_exit();
		if (*buf != '\n')
			ft_exit();
		++buf;
		h++;
	}
	buf = read_line(pos, &nb_blocks, buf, h);
	++h;
	if (h != NB_BLOCKS)
		ft_exit();
	return ((char *)buf);
}

static char		*check_tetrimino_end(const char *buf)
{
	if (*buf == '\n')
		++buf;
	else if (*buf != '\0')
		ft_exit();
	return ((char *)buf);
}

/*
** This function reads the next tetriminos, checks if it's the last tetrimino
** and then launches the pattern recognition. If the tetriminos is valid,
** a t_tetrimino is allocated whith its information.t The position is
** initialised at h -1 and w 0.
*/

static char		*read_tetrimino(t_tetrimino **new, const char *buf)
{
	t_blocks			pos;
	t_tetrimino_pattern	*pat;

	buf = read_4lines(buf, pos);
	buf = check_tetrimino_end(buf);
	pat = ft_pattern_recognition(pos);
	if (pat == NULL)
		ft_exit();
	*new = (t_tetrimino*)ft_memalloc(sizeof(t_tetrimino));
	if (*new == NULL)
		ft_exit();
	(*new)->pattern = pat;
	(*new)->pos[HEIGHT] = 0;
	(*new)->pos[WIDTH] = -1;
	return ((char*)buf);
}

/*
** This function browses the string containing the characters read in the
** input file and sends to ft_read_tetrimino the begining of each new tetrimino
*/

int				ft_read_tetriminos(t_tetrimino **tetri, int *nb_tetri,
							const char *buf)
{
	char	*pbuf;

	if (nb_tetri == NULL)
		return (0);
	pbuf = (char *)buf;
	*nb_tetri = 0;
	while (*pbuf)
	{
		if (*nb_tetri == MAX_TETRIMINOS)
			return (0);
		pbuf = read_tetrimino(&(tetri[*nb_tetri]), pbuf);
		++*nb_tetri;
		if (*pbuf == '\n')
		{
			++pbuf;
			if (*pbuf == '\0')
				return (0);
		}
		else if (*pbuf != '\0')
			return (0);
	}
	return (1);
}

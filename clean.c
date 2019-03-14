/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 21:06:17 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:42:44 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "clean.h"
#include "libft/libft.h"

t_clean	g_clean;

/*
** These functions allows the program to safely quit freeing all the
** data stored in g_clean.
*/

void	ft_clean(void)
{
	ft_free_tetris_board(g_clean.tetris);
	ft_free_patterns(g_clean.g_patterns);
	ft_free_solution(g_clean.solution);
}

void	ft_exit(void)
{
	ft_clean();
	ft_putstr(ERR_MSG);
	exit(0);
}

void	*ft_safe_alloc(size_t size)
{
	void *data;

	data = ft_memalloc(size);
	if (data == NULL)
	{
		ft_exit();
	}
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 21:07:34 by acoulomb          #+#    #+#             */
/*   Updated: 2018/04/29 20:35:23 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetri_lib.h"

/*
** This function creates a string containing information on the 19 tetriminos
** that exist : their name, height, width and pattern. It is used to generate
** the global g_patterns who contains 19 structures t_tetrimino_pattern.
*/

char	*ft_tetri_lib(char *str)
{
	ft_bzero(str, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, NB_TETRI_LIB, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_I, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_J, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_J2, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_L, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_L2, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_O, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_S, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_Z, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_T, TETRI_LIB_BUF_SIZE);
	ft_strlcat(str, TETRI_T2, TETRI_LIB_BUF_SIZE);
	return (str);
}

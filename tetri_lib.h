/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 21:07:42 by acoulomb          #+#    #+#             */
/*   Updated: 2018/04/29 20:35:22 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_LIB_H
# define TETRI_LIB_H

# define TETRI_LIB_BUF_SIZE 300
# define NB_TETRI_LIB "19\n"
# define TETRI_I "I1 4 1\n#\n#\n#\n#\nI2 1 4\n####\n"
# define TETRI_J "J1 2 3\n###\n..#\nJ2 2 3\n#..\n###\n"
# define TETRI_J2 "J3 3 2\n##\n#.\n#.\nJ4 3 2\n.#\n.#\n##\n"
# define TETRI_L "L1 2 3\n###\n#..\nL2 2 3\n..#\n###\n"
# define TETRI_L2 "L3 3 2\n#.\n#.\n##\nL4 3 2\n##\n.#\n.#\n"
# define TETRI_O "O1 2 2\n##\n##\n"
# define TETRI_S "S1 2 3\n.##\n##.\nS2 3 2\n#.\n##\n.#\n"
# define TETRI_Z "Z1 2 3\n##.\n.##\nZ2 3 2\n.#\n##\n#.\n"
# define TETRI_T "T1 2 3\n.#.\n###\nT2 2 3\n###\n.#.\n"
# define TETRI_T2 "T3 3 2\n#.\n##\n#.\nT4 3 2\n.#\n##\n.#"

char	*ft_tetri_lib(char *str);

#endif

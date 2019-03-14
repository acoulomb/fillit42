/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:12:05 by malberte          #+#    #+#             */
/*   Updated: 2018/04/29 20:55:59 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

typedef int	t_pos[2];
typedef const int	t_cpos[2];

void	poscpy(t_pos dst, t_cpos src);
void	posinit(t_pos dst, int x, int y);

#endif

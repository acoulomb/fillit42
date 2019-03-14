/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:10:18 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:01:29 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	return (ft_isalnum(c)
			|| (c >= 32 && c <= 39)
			|| (c >= 40 && c <= 47)
			|| (c >= 58 && c <= 63)
			|| (c == 64)
			|| (c >= 91 && c <= 95)
			|| (c == 96)
			|| (c >= 123 && c <= 126));
}

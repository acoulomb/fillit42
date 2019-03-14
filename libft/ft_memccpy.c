/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:43:39 by malberte          #+#    #+#             */
/*   Updated: 2018/04/21 22:44:22 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && ((unsigned char*)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		++i;
	}
	if (i == n)
		return (NULL);
	((unsigned char*)dst)[i] = (unsigned char)c;
	return (&dst[++i]);
}

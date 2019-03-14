/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:04:02 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 20:56:03 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t expected_size;
	size_t i;

	expected_size = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (ft_strlen(src) + size);
	ft_strncpy(&dst[i], src, size - i - 1);
	dst[size - 1] = '\0';
	return (expected_size);
}

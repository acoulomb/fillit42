/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:44:05 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:47:22 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t needle_size;

	if (*needle == '\0')
		return ((char*)haystack);
	needle_size = ft_strlen(needle);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, needle_size) == 0)
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}

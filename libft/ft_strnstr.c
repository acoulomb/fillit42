/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:07:09 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:46:30 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_size;

	needle_size = ft_strlen(needle);
	while (*haystack && len != 0 && needle_size <= len)
	{
		if (ft_strncmp(haystack, needle, needle_size) == 0)
			return ((char*)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}

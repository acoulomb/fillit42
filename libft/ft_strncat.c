/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:54:26 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:41:44 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_end;
	size_t	len;

	s1_end = s1;
	while (*s1_end)
		s1_end++;
	len = ft_strlen(s2);
	len = n < len ? n : len;
	ft_strncpy(s1_end, s2, len);
	s1_end[len] = '\0';
	return (s1);
}

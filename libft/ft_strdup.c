/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 23:01:58 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:19:08 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}

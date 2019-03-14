/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:13:45 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:11:26 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *s1_end;

	s1_end = s1;
	while (*s1_end)
		s1_end++;
	ft_strcpy(s1_end, s2);
	return (s1);
}

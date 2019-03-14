/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:44:10 by malberte          #+#    #+#             */
/*   Updated: 2018/04/21 21:03:16 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (1);
	--n;
	if (s1 && s2)
	{
		i = 0;
		while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
			++i;
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}

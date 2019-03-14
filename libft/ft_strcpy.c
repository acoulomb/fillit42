/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:31:30 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:13:43 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *dst_tmp;

	dst_tmp = dst;
	while (*src)
	{
		*dst_tmp = *src;
		++src;
		++dst_tmp;
	}
	*dst_tmp = '\0';
	return (dst);
}

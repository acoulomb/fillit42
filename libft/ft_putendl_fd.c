/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:17:17 by malberte          #+#    #+#             */
/*   Updated: 2018/04/15 23:15:34 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	if (s != NULL && fd != -1)
	{
		write(fd, s, ft_strlen(s));
		ft_putchar_fd('\n', fd);
	}
}

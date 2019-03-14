/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:21:15 by malberte          #+#    #+#             */
/*   Updated: 2018/04/14 01:12:55 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int div;

	if (fd != -1)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			if (n < 0)
			{
				n = -n;
				ft_putchar_fd('-', fd);
			}
			div = n / 10;
			if (div != 0)
				ft_putnbr_fd(div, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
	}
}

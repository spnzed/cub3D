/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:03:12 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/14 19:41:18 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(int i, int fd)
{
	char	c;

	c = i + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	next;
	int	rest;

	next = n / 10;
	rest = n % 10;
	if (n < 0)
	{
		next = -next;
		rest = -rest;
		write(fd, "-", 1);
	}
	if (next != 0)
	{
		ft_putnbr_fd(next, fd);
		print(rest, fd);
	}
	if (next == 0)
		print(rest, fd);
}

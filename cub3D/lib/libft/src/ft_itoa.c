/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:22:46 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/13 19:01:06 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*set_chars_pos(char	*p, int n)
{
	int	j;
	int	nb;

	nb = n;
	j = digit_count(n) - 1;
	p[digit_count(n)] = '\0';
	while (j >= 0)
	{
		p[j] = (nb % 10) + '0';
		nb = nb / 10;
		j--;
	}
	return (p);
}

static char	*set_chars_neg(char *p, int n)
{
	int	j;
	int	nb;

	nb = n;
	j = digit_count(n);
	p[0] = '-';
	p[digit_count(n) + 1] = '\0';
	while (j >= 1)
	{
		p[j] = (nb % 10) + '0';
		nb = nb / 10;
		j--;
	}
	return (p);
}

char	*itoa_int_min(void)
{
	char	*p;

	p = malloc (12);
	if (!p)
		return (NULL);
	p[0] = '-';
	p[1] = '2';
	p[2] = '1';
	p[3] = '4';
	p[4] = '7';
	p[5] = '4';
	p[6] = '8';
	p[7] = '3';
	p[8] = '6';
	p[9] = '4';
	p[10] = '8';
	p[11] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;

	if (n == -2147483648)
		return (itoa_int_min());
	else if (n < 0)
	{
		n = n * -1;
		p = malloc ((size_t)(digit_count(n) + 2));
		if (!p)
			return (NULL);
		return (set_chars_neg(p, n));
	}
	p = malloc ((size_t)(digit_count(n) + 1));
	if (!p)
		return (NULL);
	return (set_chars_pos(p, n));
}

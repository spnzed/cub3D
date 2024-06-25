/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:52:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 16:53:21 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IMAX_10 214748364

int	ft_isint(char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 0;
		str++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		if (IMAX_10 < num || (num == IMAX_10 && (str[i] - '0') > 8 - sign))
			return (0);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (i > 0);
}

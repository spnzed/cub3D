/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:45:39 by erosas-c          #+#    #+#             */
/*   Updated: 2022/01/30 16:25:40 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*dst2;
	const char		*src2;

	dst2 = (char *)dst;
	src2 = (const char *)src;
	if ((dst - src) > 0 && len > 0)
	{
		i = len;
		while (i > 0)
		{
			dst2[i - 1] = src2[i - 1];
			i--;
		}
	}
	else if ((dst - src) < 0 && len > 0)
	{
		i = 0;
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

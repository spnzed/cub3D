/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:58:53 by erosas-c          #+#    #+#             */
/*   Updated: 2022/04/06 20:31:15 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dst2;
	const char		*src2;

	dst2 = (char *)dst;
	src2 = (const char *)src;
	i = 0;
	if (src2 != NULL || dst2 != NULL)
	{
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

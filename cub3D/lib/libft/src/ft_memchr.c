/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:14 by erosas-c          #+#    #+#             */
/*   Updated: 2022/01/30 19:19:52 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while ((unsigned char)c != *s1 && i + 1 < n)
	{
		s1++;
		i++;
	}
	if (n != 0 && (unsigned char)c == *s1)
	{
		return (s1);
	}
	return (0);
}

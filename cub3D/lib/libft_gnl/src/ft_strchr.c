/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:50:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/19 12:12:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
	{
		return ((char *)s);
	}
	return (0);
}

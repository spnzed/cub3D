/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:28:18 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/02 19:30:38 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(haystack);
	if (*needle == '\0')
		return ((char *)haystack);
	while (i + ft_strlen(needle) <= len && i <= n)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) != 0)
		{
			haystack++;
			i++;
		}
		else
			return ((char *)haystack);
	}
	return (0);
}

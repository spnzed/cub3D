/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:47:36 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/08 17:05:07 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	int		n;

	i = 0;
	if (*s == '\0')
		return (ft_strdup(s));
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	n = (int)len;
	if ((size_t)start + len > ft_strlen(s))
		n = ft_strlen(s) - (size_t)start;
	p = malloc((size_t)n + 1);
	if (p == NULL)
		return (NULL);
	while (i < n)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

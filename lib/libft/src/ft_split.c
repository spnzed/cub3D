/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:44:01 by erosas-c          #+#    #+#             */
/*   Updated: 2023/01/16 21:09:09 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_ptr(char const *p, char c)
{
	while (*p == c && *p)
		p++;
	return ((char *)p);
}

static int	ft_ptr_len(char const *p, char c)
{
	int	i;

	i = 0;
	while (p[i] != c && p[i])
		i++;
	return (i);
}

static int	ft_str_count(char const *s, char c)
{
	int	str_count;
	int	j;

	str_count = 0;
	j = 0;
	if (*s == '\0')
		return (0);
	while (s[j])
	{
		if (s[j] != c && s[j + 1] == c)
		{
			str_count++;
		}
		j++;
	}
	if (s[j - 1] != c)
		str_count++;
	if (c == 0)
		str_count--;
	return (str_count);
}

static char	**free_all(char	**res, int n)
{
	while (n >= 0)
	{
		free(res[n]);
		n--;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int	str_count;
	char	**res;
	int	n;
	char	*p;

	p = 0;
	n = 0;
	if (!s)
		return (NULL);
	str_count = ft_str_count(s, c);
	res = malloc (sizeof(char *) * (str_count + 1));
	if (!res)
		return (NULL);
	while (n < str_count)
	{
		p = ft_find_ptr(s, c);
		res[n] = ft_substr(p, 0, ft_ptr_len(p, c));
		if (res[n] == NULL)
			return (free_all(res, n));
		n++;
		s = s + (p - s) + ft_ptr_len(p, c);
	}
	res[n] = NULL;
	return (res);
}

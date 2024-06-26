/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:15:39 by erosas-c          #+#    #+#             */
/*   Updated: 2024/06/27 00:49:13 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*p;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	ft_strlcat(p, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	ft_strlcat(p, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (p);
}

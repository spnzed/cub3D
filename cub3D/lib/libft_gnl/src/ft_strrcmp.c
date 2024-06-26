/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:38:34 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 14:38:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrcmp(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i > 0 && j > 0)
	{
		if (a1[i] > a2[j] || a1[i] < a2[j])
			return (a1[i] - a2[j]);
		else if (a1[i] == a2[j])
		{
			i--;
			j--;
		}
	}
	if (a1[i] > a2[j] || a1[i] < a2[j])
		return (a1[i] - a2[i]);
	else
		return (0);
}

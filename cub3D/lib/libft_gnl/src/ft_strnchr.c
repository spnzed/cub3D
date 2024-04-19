/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:36:06 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 14:36:42 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (c > 127)
		c -= 128;
	if (c == '\0')
		return (s);
	while (s[i] == (char)c)
		i++;
	return (s + i);
}

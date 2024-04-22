/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:33:38 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/22 16:33:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array_r(void **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return ;
}

void	*ft_alloc_array(size_t size, size_t h, size_t w)
{
	void	**array;
	size_t	i;

	array = malloc(sizeof(void *) * h);
	if (!array)
		return (NULL);
	i = 0;
	while (i < h)
	{
		array[i] = malloc(size * w);
		if (!array[i])
		{
			ft_free_array_r(array, i - 1);
			return (NULL);
		}
		i++;
	}
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:42:37 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/18 20:15:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrfree(char **array)
{
	int		i;
	char	*str;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		str = array[i];
		if (str)
			free(str);
		i++;
	}
	free(array);
}

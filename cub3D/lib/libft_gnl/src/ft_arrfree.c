/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:42:37 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/21 23:48:23 by aaronespino      ###   ########.fr       */
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

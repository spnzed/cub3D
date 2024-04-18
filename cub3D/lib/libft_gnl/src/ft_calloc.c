/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:33:49 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/05 18:10:40 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nb;
	char	*p;
	char	*q;
	size_t	i;

	nb = count * size;
	p = malloc(nb);
	q = p;
	i = 0;
	if (p != NULL)
		ft_bzero(p, nb);
	return (q);
}

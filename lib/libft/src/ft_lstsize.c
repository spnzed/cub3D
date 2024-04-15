/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:24:17 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/17 18:00:54 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*item;

	i = 0;
	item = lst;
	if (!lst)
		return (0);
	if (item->next == NULL)
		return (1);
	while (item->next != NULL)
	{
		item = item->next;
		i++;
	}
	return (i + 1);
}

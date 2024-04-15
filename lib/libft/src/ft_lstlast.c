/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:11:30 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/17 18:18:20 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*item;

	item = lst;
	if (!lst)
		return (NULL);
	if (item->next == NULL)
		return (item);
	while (item->next != NULL)
	{
		item = item->next;
	}
	return (item);
}

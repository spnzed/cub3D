/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:19:42 by erosas-c          #+#    #+#             */
/*   Updated: 2022/02/19 19:23:45 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_item;
	t_list	*new_lst;

	new_lst = (void *)0;
	while (lst)
	{
		new_item = ft_lstnew(f(lst->content));
		if (!new_item)
		{
			ft_lstclear(&new_lst, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_item);
		lst = lst->next;
	}
	return (new_lst);
}

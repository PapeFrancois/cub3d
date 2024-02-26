/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:44:25 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/24 16:43:07 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	no_newelem(t_list *new_elem, t_list *lst,
		t_list *new_lst, void (*del)(void *))
{
	if (!new_elem)
	{
		ft_lstclear(&lst, del);
		ft_lstclear(&new_lst, del);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst)
		return (NULL);
	new_elem = ft_lstnew((*f)(lst->content));
	if (!new_elem)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (no_newelem(new_elem, lst, new_lst, (*del)))
		{
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}

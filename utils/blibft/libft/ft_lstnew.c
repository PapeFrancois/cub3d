/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:35:31 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/24 16:44:09 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*link;

	link = (t_list *) malloc(sizeof(t_list));
	if (!link)
		return (NULL);
	link->content = (void *)content;
	link->next = NULL;
	return (link);
}

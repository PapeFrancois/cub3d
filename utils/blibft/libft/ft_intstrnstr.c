/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstrnstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <bdemetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:43:56 by bdemetz           #+#    #+#             */
/*   Updated: 2023/11/29 15:28:00 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intstrnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little == NULL || big == NULL || ft_strlen(little) == 0)
		return (-1);
	i = -1;
	while (big[++i] && i < len)
	{
		j = -1;
		while (little[++j] && j + i < len
			&& little[j] == big[i + j])
		{
			if (little[j + 1] == 0)
				return (i);
		}
	}
	return (-1);
}

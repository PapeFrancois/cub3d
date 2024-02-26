/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:43:56 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/18 18:21:16 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little == NULL || big == NULL || ft_strlen(little) == 0)
		return ((char *) big);
	i = -1;
	while (big[++i] && i < len)
	{
		j = -1;
		while (little[++j] && j + i < len
			&& little[j] == big[i + j])
		{
			if (little[j + 1] == 0)
				return ((char *) &big[i]);
		}
	}
	return (NULL);
}

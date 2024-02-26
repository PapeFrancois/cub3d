/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:20 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/18 18:17:43 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (c == 0)
		return ((char *) &s[ft_strlen(s)]);
	ptr = NULL;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c % 128)
		{
			ptr = (char *) &s[i];
		}
	}
	return (ptr);
}

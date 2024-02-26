/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:48:58 by bdemetz           #+#    #+#             */
/*   Updated: 2023/09/13 15:20:09 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *) dest;
	i = 0;
	if (dest > src)
	{
		while (n-- > 0)
		{
			dest2[n] = src2[n];
		}
		return (dest);
	}
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

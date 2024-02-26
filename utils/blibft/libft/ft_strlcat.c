/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:48:46 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/24 16:34:12 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!dest)
		return (0);
	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = 0;
	if (size <= i)
		j = j + size;
	else
		j = j + i;
	while (i + 1 < size && src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	if (i <= size)
		dest[i] = '\0';
	return (j);
}

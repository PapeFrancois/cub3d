/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:20 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/17 16:39:08 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned char	*str;
	unsigned char	cc;

	if (!s)
		return (NULL);
	str = (unsigned char *) s;
	i = -1;
	cc = (unsigned char) c;
	while (++i < n)
		if (str[i] == cc)
			return (&str[i]);
	return (NULL);
}

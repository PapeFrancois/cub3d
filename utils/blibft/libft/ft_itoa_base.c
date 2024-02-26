/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:35:26 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/24 15:40:17 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_i_b2(unsigned int tmp, char *base, int count, char *res)
{
	unsigned int	base_length;

	base_length = ft_strlen(base);
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}

unsigned int	tmp_reset(int value, int *count)
{
	unsigned int	tmp;

	tmp = value;
	if (value < 0)
	{
		*count = 2;
		tmp = -value;
	}
	return (tmp);
}

char	*ft_itoa_base(int value, char *base)
{
	int					count;
	unsigned int		tmp;
	char				*res;
	unsigned int		base_length;

	base_length = ft_strlen(base);
	count = 1;
	tmp = tmp_reset(value, &count);
	while (tmp >= base_length && (tmp / base_length))
	{
		++count;
		tmp = tmp / base_length;
	}
	tmp = tmp_reset(value, &count);
	res = (char *) ft_calloc(sizeof(char), count + 1);
	if (!res)
		return (NULL);
	if (value < 0)
		res[0] = '-';
	res[count] = '\0';
	res = ft_i_b2(tmp, base, count, res);
	return (res);
}

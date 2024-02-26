/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:35:26 by bdemetz           #+#    #+#             */
/*   Updated: 2023/12/17 12:21:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 && n > -2147483648)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(long int n)
{
	char			*str;
	int				i;
	unsigned int	size;
	unsigned int	tmp;

	size = ft_itoa_size(n);
	i = 1;
	str = (char *) ft_calloc(ft_itoa_size(n) + 2, sizeof(char));
	if (!str)
		return (0);
	tmp = n;
	if (n < 0)
		tmp = -tmp;
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (n < 0)
		*str = '-';
	str[size] = '\0';
	return (str);
}

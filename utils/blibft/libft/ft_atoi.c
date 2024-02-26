/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:35:04 by bdemetz           #+#    #+#             */
/*   Updated: 2023/10/13 13:37:00 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	i = -1;
	while (nptr[++i] && !ft_isdigit(nptr[i]))
		if (nptr[i] == 45)
			sign = -sign;
	i = -1;
	while ((nptr[++i] > 6 && nptr[i] < 14) || nptr[i] == 32)
		;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	i--;
	while (nptr[++i] && ft_isdigit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - 48);
	}
	result = result * sign;
	return (result);
}

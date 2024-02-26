/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_long_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <bdemetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:10:33 by bdemetz           #+#    #+#             */
/*   Updated: 2023/12/17 20:43:53 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_long_long(unsigned long long nbr, char *base)
{
	unsigned long long	base_size;
	unsigned long long	unit;
	unsigned long long	cpt;

	cpt = 0;
	base_size = ft_strlen(base);
	if (nbr < base_size && nbr > 0)
	{
		cpt = check_w(cpt, write(1, &base[nbr], 1));
		return (cpt);
	}
	unit = nbr / base_size;
	cpt = check_w(cpt, ft_putnbr_base_long_long(unit, base));
	cpt = check_w(cpt, write(1, &base[nbr % base_size], 1));
	return (cpt);
}

int	ft_putunsigned_long_long(unsigned long long n)
{
	int		i;
	char	c;
	int		cpt;

	cpt = 0;
	i = n % 10;
	c = i + 48;
	if (n < 10)
		return (write (1, &c, 1));
	cpt = check_w(cpt, ft_putunsigned_long_long(n / 10));
	cpt = check_w(cpt, write (1, &c, 1));
	return (cpt);
}

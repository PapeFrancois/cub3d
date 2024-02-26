/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <bdemetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:13:38 by bdemetz           #+#    #+#             */
/*   Updated: 2023/12/17 20:44:18 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_size;
	unsigned int	unit;
	unsigned int	cpt;

	cpt = 0;
	base_size = ft_strlen(base);
	if (nbr < base_size)
	{
		cpt = check_w(cpt, write(1, &base[nbr], 1));
		return (cpt);
	}
	unit = nbr / base_size;
	cpt = check_w(cpt, ft_putnbr_base(unit, base));
	cpt = check_w(cpt, write(1, &base[nbr % base_size], 1));
	return (cpt);
}

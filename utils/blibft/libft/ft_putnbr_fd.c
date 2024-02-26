/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:44:21 by bdemetz           #+#    #+#             */
/*   Updated: 2023/01/05 17:16:16 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rcrsv_print(unsigned int n, int fd)
{
	int		i;
	char	c;
	int		cpt;

	cpt = 0;
	i = n % 10;
	c = i + 48;
	if (n < 10)
	{
		return (write (fd, &c, 1));
	}
	cpt = check_w(cpt, rcrsv_print(n / 10, fd));
	cpt = check_w(cpt, write (fd, &c, 1));
	return ((cpt));
}

int	ft_putnbr_fd(int n, int fd)
{
	int	cpt;

	cpt = 0;
	if (n < 0)
	{
		cpt = check_w(cpt, write(fd, "-", 1));
		cpt = check_w(cpt, rcrsv_print((unsigned int) -n, fd));
	}
	else
		cpt = check_w(cpt, rcrsv_print((unsigned int) n, fd));
	return (cpt);
}

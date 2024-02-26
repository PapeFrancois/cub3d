/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:44:21 by bdemetz           #+#    #+#             */
/*   Updated: 2023/01/03 17:24:10 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int		i;
	char	c;
	int		cpt;

	cpt = 0;
	i = n % 10;
	c = i + 48;
	if (n < 10)
		return (write (fd, &c, 1));
	cpt = check_w(cpt, ft_putunsigned_fd(n / 10, fd));
	cpt = check_w(cpt, write (fd, &c, 1));
	return (cpt);
}

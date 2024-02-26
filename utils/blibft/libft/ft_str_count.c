/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:28:24 by codespace         #+#    #+#             */
/*   Updated: 2023/12/17 20:32:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_count(char *str, char *to_find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
		{
			count++;
			i += ft_strlen(to_find);
		}
		else
			i++;
	}
	return (count);
}

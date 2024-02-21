/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:11:08 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/21 14:44:56 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	malloc_error(char **table, int i)
{
	while (i >= 0)
	{
		free(table[i]);
		i--;
	}
	free(table);
}

void	free_elements(t_elements elements)
{
	if (elements.no)
		free(elements.no);
	if (elements.so)
		free(elements.so);
	if (elements.we)
		free(elements.we);
	if (elements.ea)
		free(elements.ea);
	if (elements.map)
		free_table(elements.map);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

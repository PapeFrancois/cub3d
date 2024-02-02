/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:11:08 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/02 11:21:00 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (elements.NO)
		free(elements.NO);
	if (elements.SO)
		free(elements.SO);
	if (elements.WE)
		free(elements.WE);
	if (elements.EA)
		free(elements.EA);
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

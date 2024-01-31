/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:11:08 by hepompid          #+#    #+#             */
/*   Updated: 2024/01/31 18:34:21 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

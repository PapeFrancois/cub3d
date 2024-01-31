/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:39 by hepompid          #+#    #+#             */
/*   Updated: 2024/01/31 18:35:17 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	data_assigner(char ***texture_path, char *texture_line, int start, int end)
{
	int	i;
	
	**texture_path = NULL;
	**texture_path = malloc((end - start + 2) * sizeof(char));
	if (!(**texture_path))
	{
		printf("Error\nA malloc failed\n");
		return (ERROR);
	}
	i = 0;
	while (start <= end)
	{
		(**texture_path)[i] = texture_line[start];
		start++;
		i++;
	}
	(**texture_path)[i] = 0;
	return (OK);
}

int	data_catcher(char **texture_path, char *texture_line)
{
	int	i;
	int	j;

	i = 0;
	while (texture_line[i] && (texture_line[i] == ' ' || texture_line[i] == '\n'))
		i++;
	if (texture_line[i])
		i += 2;
	while (texture_line[i] && (texture_line[i] == ' ' || texture_line[i] == '\n'))
		i++;
	if (!texture_line[i] || texture_line[i] == '\n')
	{
		printf("custom error message\n");
		return (ERROR);
	}
	j = ft_strlen(texture_line) - 1;
	while (j >= 0 && (texture_line[j] == ' ' || texture_line[j] == '\n'))
		j--;
	if (data_assigner(&texture_path, texture_line, i, j) == ERROR)
		return (ERROR);
	return (OK);
}

int	element_manager(char **file, int n_of_lines, t_elements *elements)
{
	t_preli		temp_elements;
	
	if (file_decomposer(&temp_elements, n_of_lines, file) == ERROR)
		return (ERROR);
	elements->map = NULL;
	if (map_manager(&elements->map, temp_elements.map) == ERROR)
	{
		free_table(temp_elements.map);
		return (ERROR);
	}
	free(temp_elements.map);
	if (data_catcher(&elements->NO, temp_elements.NO) == ERROR)
		return (ERROR);
	if (data_catcher(&elements->SO, temp_elements.SO) == ERROR)
		return (ERROR);
	if (data_catcher(&elements->WE, temp_elements.WE) == ERROR)
		return (ERROR);
	if (data_catcher(&elements->EA, temp_elements.EA) == ERROR)
		return (ERROR);
	return (OK);
}

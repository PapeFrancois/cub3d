/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:39 by hepompid          #+#    #+#             */
/*   Updated: 2024/01/31 14:28:47 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	path_assigner(char ***texture_path, char *texture_line, int i, int j)
{
	**texture_path = malloc((j - i + 2) * sizeof(char));
	if (!(**texture_path))
	{
		printf("Error\nA malloc failed\n");
		return (ERROR);
	}
	while (i <= j)
	{
		**texture_path[i] = texture_line[i];
		i++;
	}
	**texture_path[i] = 0;
	return (OK);
}

int	path_catcher(char **texture_path, char *texture_line)
{
	int	i;
	int	j;

	i = 0;
	while (texture_line[i] && texture_line[i] != ' ' && texture_line[i] != '\n')
		i++;
	if (texture_line[i] && texture_line[i] != '\n')
		i += 2;
	while (texture_line[i] && texture_line[i] != ' ' && texture_line[i] != '\n')
		i++;
	if (!texture_line[i] || texture_line[i] == '\n')
	{
		printf("custom error message\n");
		return (ERROR);
	}
	j = ft_strlen(texture_line) - 1;
	while (texture_line[j] == ' ')
		j--;
	if (path_assigner(&texture_path, texture_line, i, j) == ERROR)
		return (ERROR);
	return (OK);
}

int	element_manager(char **file, int n_of_lines, t_elements *elements)
{
	t_preli		temp_elements;
	
	if (file_decomposer(&temp_elements, n_of_lines, file) == ERROR)
	{
		free_table(file);
		return (ERROR);
	}
	elements->map = NULL;
	if (map_manager(&elements->map, temp_elements.map) == ERROR)
	{
		free_table(temp_elements.map);
		return (ERROR);
	}
	free(temp_elements.map);
	// if (path_catcher(&elements->NO, temp_elements.NO) == ERROR);
	
	int i = 0;
	while (elements->map[i])
	{
		printf("%s\n", elements->map[i]);
		i++;
	}
	return (OK);
}

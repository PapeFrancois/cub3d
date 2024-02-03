/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:39 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 10:32:21 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	texture_assigner(char ***texture_path, char *texture_line, int start, int end)
{
	int	i;

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

static int	texture_manager(char **texture_path, char *texture_line)
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
		return (err("Texture linking error\n"));
	j = ft_strlen(texture_line) - 1;
	while (j >= 0 && (texture_line[j] == ' ' || texture_line[j] == '\n'))
		j--;
	if (texture_assigner(&texture_path, texture_line, i, j) == ERROR)
		return (ERROR);
	return (OK);
}

static int	texture_checker(t_elements **elements)
{
	int	fd;

	fd = open((*elements)->NO, O_RDONLY);
	if (fd == -1)
		return (err("Failed to open texture\n"));
	close(fd);
	fd = open((*elements)->SO, O_RDONLY);
	if (fd == -1)
		return (err("Failed to open texture\n"));
	close(fd);
	fd = open((*elements)->WE, O_RDONLY);
	if (fd == -1)
		return (err("Failed to open texture\n"));
	close(fd);
	fd = open((*elements)->EA, O_RDONLY);
	if (fd == -1)
		return (err("Failed to open texture\n"));
	close(fd);
	return (OK);
}

int	element_manager(char **file, int n_of_lines, t_elements **elements)
{
	t_preli		temp_elements;

	if (file_decomposer(&temp_elements, n_of_lines, file) == ERROR)
		return (ERROR);
	if (map_manager(&(*elements)->map, temp_elements.map) == ERROR)
	{
		free_table(temp_elements.map);
		return (ERROR);
	}
	free(temp_elements.map);
	if (texture_manager(&(*elements)->NO, temp_elements.NO) == ERROR)
		return (ERROR);
	if (texture_manager(&(*elements)->SO, temp_elements.SO) == ERROR)
		return (ERROR);
	if (texture_manager(&(*elements)->WE, temp_elements.WE) == ERROR)
		return (ERROR);
	if (texture_manager(&(*elements)->EA, temp_elements.EA) == ERROR)
		return (ERROR);
	if (colors_manager(&(*elements)->F, temp_elements.F) == ERROR)
		return (ERROR);
	if (colors_manager(&(*elements)->C, temp_elements.C) == ERROR)
		return (ERROR);
	if (texture_checker(elements) == ERROR)
		return (ERROR);
	if (map_checker((*elements)->map) == ERROR)
		return (ERROR);
	return (OK);
}

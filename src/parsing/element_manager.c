/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:39 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/21 14:45:24 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static int	txtr_assignr(char ***txtr_path, char *txtr_line, int start, int end)
{
	int	i;

	**txtr_path = malloc((end - start + 2) * sizeof(char));
	if (!(**txtr_path))
	{
		printf("Error\nA malloc failed\n");
		return (ERROR);
	}
	i = 0;
	while (start <= end)
	{
		(**txtr_path)[i] = txtr_line[start];
		start++;
		i++;
	}
	(**txtr_path)[i] = 0;
	return (OK);
}

static int	texture_manager(char **texture_path, char *txtr_line)
{
	int	i;
	int	j;

	i = 0;
	while (txtr_line[i] && (txtr_line[i] == ' ' || txtr_line[i] == '\n'))
		i++;
	if (txtr_line[i])
		i += 2;
	while (txtr_line[i] && (txtr_line[i] == ' ' || txtr_line[i] == '\n'))
		i++;
	if (!txtr_line[i] || txtr_line[i] == '\n')
		return (err("Texture linking error\n"));
	j = ft_strlen(txtr_line) - 1;
	while (j >= 0 && (txtr_line[j] == ' ' || txtr_line[j] == '\n'))
		j--;
	if (txtr_assignr(&texture_path, txtr_line, i, j) == ERROR)
		return (ERROR);
	return (OK);
}

static int	texture_checker(t_elements **elements)
{
	int	fd;

	fd = open((*elements)->no, O_RDONLY);
	if (fd == -1)
		return (err("failed to open texture\n"));
	close(fd);
	fd = open((*elements)->so, O_RDONLY);
	if (fd == -1)
		return (err("failed to open texture\n"));
	close(fd);
	fd = open((*elements)->we, O_RDONLY);
	if (fd == -1)
		return (err("failed to open texture\n"));
	close(fd);
	fd = open((*elements)->ea, O_RDONLY);
	if (fd == -1)
		return (err("failed to open texture\n"));
	close(fd);
	return (OK);
}

static int	element_checker(t_elements **elements)
{
	if (texture_checker(elements) == ERROR)
		return (ERROR);
	if (map_checker((*elements)->map) == ERROR)
		return (ERROR);
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
	if (texture_manager(&(*elements)->no, temp_elements.no) == ERROR)
		return (ERROR);
	if (texture_manager(&(*elements)->so, temp_elements.so) == ERROR)
		return (ERROR);
	if (texture_manager(&(*elements)->we, temp_elements.we) == ERROR)
		return (ERROR);
	if (texture_manager(&(*elements)->ea, temp_elements.ea) == ERROR)
		return (ERROR);
	if (colors_manager(&(*elements)->f, temp_elements.f) == ERROR)
		return (ERROR);
	if (colors_manager(&(*elements)->c, temp_elements.c) == ERROR)
		return (ERROR);
	if (element_checker(elements) == ERROR)
		return (ERROR);
	return (OK);
}

// void	preli_printer(t_preli elements)
// {
// 	int	i;
// 	printf("PRELI PRINTING\n");
// 	printf("NO = %sSO = %sWE = %sEA = %sF = %sC = %s", 
// 	elements.no, elements. so, elements.we, 
// 	elements.ea, elements.f, elements.c);
// 	i = 0;
// 	while (elements.map[i])
// 	{
// 		printf("%s", elements.map[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

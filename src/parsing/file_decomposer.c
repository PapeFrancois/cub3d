/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_decomposer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:57:05 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 10:32:59 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	element_searcher(char *line, t_preli **elements)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] == '\n')
		return (OK);
	if (!(**elements).NO && line[i] == 'N' && line[i + 1] == 'O')
		(**elements).NO = line;
	else if (!(**elements).SO && line[i] == 'S' && line[i + 1] == 'O')
		(**elements).SO = line;
	else if (!(**elements).WE && line[i] == 'W' && line[i + 1] == 'E')
		(**elements).WE = line;
	else if (!(**elements).EA && line[i] == 'E' && line[i + 1] == 'A')
		(**elements).EA = line;
	else if (!(**elements).F && line[i] == 'F')
		(**elements).F = line;
	else if (!(**elements).C && line[i] == 'C')
		(**elements).C = line;
	else
		return (err("Texture missing"));
	if ((**elements).NO && (**elements).SO && (**elements).WE
		&& (**elements).EA && (**elements).F && (**elements).C)
		return (DONE);
	return (OK);
}

static int	map_searcher(char **file, int i, char ***map, int n_of_lines)
{
	int	j;

	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] != ' ' && file[i][j] != '\n')
				break ;
		}
		if (file[i][j])
			break ;
	}
	if (!file[i])
		return (err("Map missing"));
	*map = malloc((n_of_lines - i + 1) * sizeof(char *));
	if (!(*map))
	{
		printf("Error\nA malloc failed\n");
		return (ERROR);
	}
	j = 0;
	while (file[i])
		(*map)[j++] = file[i++];
	(*map)[j] = NULL;
	return (OK);
}

int	file_decomposer(t_preli *elements, int n_of_lines, char **file)
{
	int	i;
	int	status;

	elements->NO = NULL;
	elements->SO = NULL;
	elements->WE = NULL;
	elements->EA = NULL;
	elements->F = NULL;
	elements->C = NULL;
	i = -1;
	while (file[++i])
	{
		status = element_searcher(file[i], &elements);
		if (status == ERROR)
			return (ERROR);
		else if (status == DONE)
			break ;
	}
	elements->map = NULL;
	if (map_searcher(file, i, &elements->map, n_of_lines) == ERROR)
		return (ERROR);
	return (OK);
}

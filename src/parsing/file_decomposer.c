/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_decomposer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:57:05 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 11:14:24 by hepompid         ###   ########.fr       */
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
	if (!(**elements).no && line[i] == 'N' && line[i + 1] == 'O')
		(**elements).no = line;
	else if (!(**elements).so && line[i] == 'S' && line[i + 1] == 'O')
		(**elements).so = line;
	else if (!(**elements).we && line[i] == 'W' && line[i + 1] == 'E')
		(**elements).we = line;
	else if (!(**elements).ea && line[i] == 'E' && line[i + 1] == 'A')
		(**elements).ea = line;
	else if (!(**elements).f && line[i] == 'F')
		(**elements).f = line;
	else if (!(**elements).c && line[i] == 'C')
		(**elements).c = line;
	else
		return (err("Texture or color missing"));
	if ((**elements).no && (**elements).so && (**elements).we
		&& (**elements).ea && (**elements).f && (**elements).c)
		return (DONE);
	return (OK);
}

static char	***temp_map_filler(char **file, int i, char ***map)
{
	int	j;

	j = 0;
	while (file[i])
		(*map)[j++] = file[i++];
	(*map)[j] = NULL;
	return (map);
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
	map = temp_map_filler(file, i, map);
	return (OK);
}

int	file_decomposer(t_preli *elements, int n_of_lines, char **file)
{
	int	i;
	int	status;

	elements->no = NULL;
	elements->so = NULL;
	elements->we = NULL;
	elements->ea = NULL;
	elements->f = NULL;
	elements->c = NULL;
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

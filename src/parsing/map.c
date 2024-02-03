/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:14:09 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 10:51:58 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	max_len_finder(char **temp_map)
{
	int	i;
	int	j;
	int	len_max;

	len_max = 0;
	i = 0;
	while (temp_map[i])
	{
		j = 0;
		while (temp_map[i][j])
			j++;
		if (j > len_max)
		{
			if (temp_map[i][j - 1] == '\n')
				len_max = j - 1;
			else
				len_max = j;
		}
		i++;
	}
	return (len_max);
}

static int	map_size_finder(char **temp_map)
{
	int	i;
	int	j;

	i = 0;
	while (temp_map[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = 0;
		while (temp_map[i][j])
		{
			if (temp_map[i][j] != ' ' && temp_map[i][j] != '\n')
				break ;
			j++;
		}
		if (temp_map[i][j])
			break ;
		i--;
	}
	return (i + 1);
}

static char	*line_filler(char *final_line, char *temp_line, int len_max)
{
	int	i;

	i = 0;
	while (temp_line[i] && temp_line[i] != '\n')
	{
		final_line[i] = temp_line[i];
		i++;
	}
	while (i < len_max)
	{
		final_line[i] = ' ';
		i++;
	}
	final_line[i] = 0;
	return (final_line);
}

int	map_manager(char ***final_map, char **temp_map)
{
	int	i;
	int	len;

	len = max_len_finder(temp_map);
	*final_map = malloc((len + 1) * sizeof(char *));
	if (!(*final_map))
	{
		printf("Error\nA malloc failed\n");
		return (ERROR);
	}
	i = 0;
	while (i < map_size_finder(temp_map))
	{
		(*final_map)[i] = malloc((max_len_finder(temp_map) + 1) * sizeof(char));
		if (!(*final_map)[i])
		{
			malloc_error(*final_map, i - 1);
			printf("Error\nA malloc failed\n");
			return (ERROR);
		}
		(*final_map)[i] = line_filler((*final_map)[i], temp_map[i], len);
		i++;
	}
	(*final_map)[i] = NULL;
	return (OK);
}

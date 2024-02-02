/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:58:27 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/02 11:24:33 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	starting_point_finder(char *starting_point, char point)
{
	if (point != '0' && point != '1' && point != ' ' && *starting_point)
		return (ERROR);
	else if (point != '0' && point != '1' && point != ' ' && !(*starting_point))
		*starting_point = point;
	return (OK);
}

void	lentgh_and_width_finder(int *length, int *width, char **map)
{
	*length = 0;
	while (map[*length])
		(*length)++;
	*width = 0;
	while (map[0][*width])
		(*width)++;
}

int	walls_checker(int length, int width, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || (i > 0 && map[i - 1][j] == ' ' ))
					return (ERROR);
				if (i == length - 1 || (i < length - 1 && map[i + 1][j] == ' '))
					return (ERROR);
				if (j == 0 || (j > 0 && map[i][j - 1] == ' '))
					return (ERROR);
				if (j == width - 1 || (i < width - 1 && map[i][j + 1] == ' '))
					return (ERROR);
			}
		}
	}
	return (OK);
}

int	map_checker(char **map)
{
	int		i;
	int		j;
	int		length;
	int		width;
	char	starting_point;

	lentgh_and_width_finder(&length, &width, map);
	starting_point = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (starting_point_finder(&starting_point, map[i][j]) == ERROR)
				return (ERROR);
		}
	}
	if (starting_point == 0)
		return (ERROR);
	if (walls_checker(length, width, map) == ERROR)
		return (ERROR);
	return (OK);
}
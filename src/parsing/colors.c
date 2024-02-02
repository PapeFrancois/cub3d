/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:45:29 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/02 17:50:00 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	color_splitter(char *color_line, int *end)
{
	int	start;

	while (color_line[*end] && color_line[*end] == '\n' && color_line[*end] == ' ')
		(*end)++;
	start = *end;
	while (color_line[*end] && color_line[*end] != '\n' && color_line[*end] != ',')
	{
		if (!ft_isdigit(color_line[*end]))
			return (-1);
		(*end)++;
	}
	if (color_line[*end])
	{
		color_line[*end] = 0;
		(*end)++;
	}
	while (color_line[*end] && color_line[*end] == ' ')
		(*end)++;
	return (ft_atoi(color_line + start));
}

int	colors_manager(long int *color, char *color_line)
{
	t_colors	colors;
	int			i;

	colors.RED = -1;
	colors.GREEN = -1;
	colors.BLUE = -1;
	i = 0;
	while (color_line[i] && (color_line[i] == ' ' || color_line[i] == '\n'))
		i++;
	if (color_line[i])
		i++;
	while (color_line[i] && (color_line[i] == ' ' || color_line[i] == '\n'))
		i++;
	colors.RED = color_splitter(color_line, &i);
	colors.GREEN = color_splitter(color_line, &i);
	colors.BLUE = color_splitter(color_line, &i);
	if (colors.RED < 0 || colors.RED > 255 || colors.GREEN < 0
		|| colors.GREEN > 255 || colors.BLUE < 0 || colors.BLUE > 255)
		return (err("Color issue"));
	*color = (colors.RED << 16) + (colors.GREEN << 8) + colors.BLUE;
	return (OK);
}

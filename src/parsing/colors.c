/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:45:29 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 10:53:31 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	color_splitter(char *clr_line, int *end)
{
	int	start;

	while (clr_line[*end] && clr_line[*end] == '\n' && clr_line[*end] == ' ')
		(*end)++;
	start = *end;
	while (clr_line[*end] && clr_line[*end] != '\n' && clr_line[*end] != ',')
	{
		if (!ft_isdigit(clr_line[*end]))
			return (-1);
		(*end)++;
	}
	if (clr_line[*end])
	{
		clr_line[*end] = 0;
		(*end)++;
	}
	while (clr_line[*end] && clr_line[*end] == ' ')
		(*end)++;
	return (ft_atoi(clr_line + start));
}

int	colors_manager(long int *color, char *color_line)
{
	t_colors	colors;
	int			i;

	colors.red = -1;
	colors.green = -1;
	colors.blue = -1;
	i = 0;
	while (color_line[i] && (color_line[i] == ' ' || color_line[i] == '\n'))
		i++;
	if (color_line[i])
		i++;
	while (color_line[i] && (color_line[i] == ' ' || color_line[i] == '\n'))
		i++;
	colors.red = color_splitter(color_line, &i);
	colors.green = color_splitter(color_line, &i);
	colors.blue = color_splitter(color_line, &i);
	if (colors.red < 0 || colors.red > 255 || colors.green < 0
		|| colors.green > 255 || colors.blue < 0 || colors.blue > 255)
		return (err("Color issue"));
	*color = (colors.red << 16) + (colors.green << 8) + colors.blue;
	return (OK);
}

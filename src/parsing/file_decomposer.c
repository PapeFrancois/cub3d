/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_decomposer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:57:05 by hepompid          #+#    #+#             */
/*   Updated: 2024/01/29 16:54:07 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	element_assigner(t_elements **elm, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] && str[i] == 'N' && str[i + 1] == 'O' && (*elm)->NO == NULL)
		(*elm)->NO = str;
	else if (str[i] && str[i] == 'S' && str[i + 1] == 'O' && (*elm)->SO == NULL)
		(*elm)->SO = str;
	else if (str[i] && str[i] == 'W' && str[i + 1] == 'E' && (*elm)->WE == NULL)
		(*elm)->WE = str;
	else if (str[i] && str[i] == 'E' && str[i + 1] == 'A' && (*elm)->EA == NULL)
		(*elm)->EA = str;
	else if (str[i] && str[i] == 'F' && (*elm)->F == NULL)
		(*elm)->F = str;
	else if (str[i] && str[i] == 'C' && (*elm)->C == NULL)
		(*elm)->C = str;
	else if (str[i])
		return (ERROR);
	if ((*elm)->NO && (*elm)->SO && (*elm)->WE && (*elm)->EA
		&& (*elm)->F && (*elm)->C)
		return (DONE);
	return (OK);
}

int	file_decomposer(t_elements *element, int fd)
{
	char	*str;
	int		status;

	str = get_next_line(fd);
	status = element_assigner(&element, fd);
	while (str && status == OK)
	{
		free(str);
		str = get_next_line(fd);
		status = element_assigner(&element, fd);
	}
	if (!str)
		return (ERROR);
	if (status == ERROR)
		return (ERROR);
	free(str);
	map_handler(&(element->map), fd);
}

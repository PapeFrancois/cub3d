/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:18:28 by hepompid          #+#    #+#             */
/*   Updated: 2024/01/29 13:53:15 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	extension_checker(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i + 1])
		i++;
	if (arg[i] != 'b' && arg[i - 1] != 'u' && arg[i - 2] != 'c'
			&& arg[i - 3] != '.')
	{
		printf("Error\nThe file must have a .cub extention\n");
		return (ERROR);
	}
	return (OK);
}

static int	file_exist_checker(char *arg, int *fd)
{
	*fd = open(arg, O_RDONLY);
	if (*fd == -1)
	{
		printf("Error\nAn error occured whilst trying to open the file\n");
		close(*fd);
		return (ERROR);
	}
	return (OK);
}

int	parsing(char *arg)
{
	int			fd;
	t_elements	elements;
	
	if (extension_checker(arg) == ERROR || file_exist_checker(arg, &fd) == ERROR)
		return (ERROR);
	elements.NO = NULL;
	elements.SO = NULL;
	elements.WE = NULL;
	elements.EA = NULL;
	elements.C = NULL;
	elements.F = NULL;
	elements.map = NULL;
	return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:18:28 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/02 17:46:21 by hepompid         ###   ########.fr       */
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
		return (err("The file must have a .cub extention"));
	return (OK);
}

static int	file_opener(char *arg, int *fd)
{
	*fd = open(arg, O_RDONLY);
	if (*fd == -1)
	{
		close(*fd);
		return (err("The file failed to open"));
	}
	return (OK);
}

static int	line_counter(int fd)
{
	char	buffer;
	int		n_of_lines;

	n_of_lines = 0;
	while (read(fd, &buffer, 1))
	{
		if (n_of_lines == 0)
			n_of_lines = 1;
		if (buffer == '\n')
			n_of_lines++;
	}
	close(fd);
	return (n_of_lines);
}

static int	table_filler(char ***file, int fd, int n_of_lines)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		(*file)[i] = str;
		i++;
		str = get_next_line(fd);
	}
	if (!str && i < n_of_lines - 1)
	{
		malloc_error(*file, i - 1);
		printf("Error\nA malloc failed\n");
		return (ERROR);
	}
	(*file)[i] = NULL;
	return (OK);
}

int	parsing(char *arg)
{
	int			fd;
	int			n_of_lines;
	char		**file;
	t_elements	elements;

	elements.NO = NULL;
	elements.SO = NULL;
	elements.WE = NULL;
	elements.EA = NULL;
	elements.map = NULL;
	if (extension_checker(arg) == ERROR || file_opener(arg, &fd) == ERROR)
		return (ERROR);
	n_of_lines = line_counter(fd);
	if (file_opener(arg, &fd) == ERROR)
		return (ERROR);
	file = malloc((n_of_lines + 1) * sizeof(char *));
	if (!file || table_filler(&file, fd, n_of_lines) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	if (element_manager(file, n_of_lines, &elements) == ERROR)
	{
		free_table(file);
		free_elements(elements);
		return (ERROR);
	}
	free_table(file);
	free_elements(elements);
	return (OK);
}

// void	preli_printer(t_preli elements)
// {
// 	int	i;
	
// 	printf("NO = %sSO = %sWE = %sEA = %sF = %sC = %s", 
// 		elements.NO, elements. SO, elements.WE, elements.EA, elements.F, elements.C);
// 	i = 0;
// 	while (elements.map[i])
// 	{
// 		printf("%s", elements.map[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

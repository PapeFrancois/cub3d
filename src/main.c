/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:37:03 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/21 14:57:47 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_elements	elements;

	elements.no = NULL;
	elements.so = NULL;
	elements.we = NULL;
	elements.ea = NULL;
	elements.map = NULL;
	if (argc != 2)
	{
		printf("Error\nThe program is expecting one argument\n");
		return (0);
	}
	if (parsing(argv[1], &elements) == ERROR)
	{
		free_elements(elements);
		return (1);
	}
	raycasting(elements);
	free_elements(elements);
	return (0);
}

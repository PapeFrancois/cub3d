/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:35:33 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 11:18:29 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_elements	t_elements;

typedef struct s_preli
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
}	t_preli;

typedef struct s_colors
{
	int			red;
	int			green;
	int			blue;
}	t_colors;

void	malloc_error(char **table, int i);
int		file_decomposer(t_preli *elements, int n_of_lines, char **file);
void	free_table(char **table);
int		map_manager(char ***final_map, char **temp_map);
int		element_manager(char **file, int n_of_lines, t_elements **elements);
void	free_elements(t_elements elements);
int		colors_manager(long int *color, char *color_line);
int		map_checker(char **map);
int		err(char *message);

#endif

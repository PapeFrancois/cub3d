/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:35:33 by hepompid          #+#    #+#             */
/*   Updated: 2024/01/31 18:34:32 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct	s_preli
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	**map;
}	t_preli;

typedef struct	s_elements
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	long int	F;
	long int	C;
	char		**map;
}	t_elements;

void	malloc_error(char **table, int i);
int		file_decomposer(t_preli *elements, int n_of_lines, char **file);
void	free_table(char **table);
int		map_manager(char ***final_map, char **temp_map);
int		element_manager(char **file, int n_of_lines, t_elements *elements);
void	free_elements(t_elements elements);

#endif

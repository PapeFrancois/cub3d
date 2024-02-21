/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:31:31 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/21 14:46:34 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "../utils/libft/libft.h"

# define OK 0
# define ERROR 1
# define DONE 2

typedef struct s_elements
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	long int	f;
	long int	c;
	char		**map;
}	t_elements;

int	parsing(char *arg, t_elements *elements);
void	free_elements(t_elements elements);
int raycasting(void);

#endif

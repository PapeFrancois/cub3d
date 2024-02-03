/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:31:31 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 10:27:31 by hepompid         ###   ########.fr       */
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
# include "../utils/get_next_line/get_next_line.h"

# include "parsing.h"

# define OK 0
# define ERROR 1
# define DONE 2

int	parsing(char *arg, t_elements *elements);

#endif

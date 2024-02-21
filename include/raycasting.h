/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:28:15 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/21 15:05:31 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
# include "cub3d.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_elements t_elements;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_elements	elements;
}	t_game;

#endif

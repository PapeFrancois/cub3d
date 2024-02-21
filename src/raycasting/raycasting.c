/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:30:40 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/21 15:03:33 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raycasting.h"

int	raycasting(t_elements elements)
{
	t_game game;
	
	game.elements = elements;
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1200, 800, "cub3d");
	
	mlx_loop(game.mlx);
	return (0);
}

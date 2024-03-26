
#include "../../include/graphic.h"

static void draw_2d_player(t_game *game)
{
	(void)game;
	for (int i = 0; i < 0 + 5; i++)
	{
		for (int j = 0; j < 0 + 5; j++)
		{
			*(unsigned int *)(game->img->data + (int) (((int) (game->y * MAP_SIZE)+i) * game->img->size_line + (j + ((int) game->x * MAP_SIZE)) * (game->img->bits_per_pixel / 8))) = 0x00FFFFFF;
		}
	}
}

 static void	draw_2d_map(t_game *game)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		size;

	size = MAP_SIZE;
	i = 0;
	while (game->display->map[i])
	{
		j = 0;
		while (game->display->map[i][j])
		{
			if (game->display->map[i][j] == '1')
			{
				k = 0;
				while (k < size)
				{
					l = 0;
					while (l < size)
					{
						// mlx_pixel_put(game->display->mlx, game->display->win, i * MAP_SIZE + l, j * MAP_SIZE + k, 0x00FFFFFF);
						*(unsigned int *)(game->img->data + (int) ((i * MAP_SIZE + l) * game->img->size_line + (j*MAP_SIZE+k) * (game->img->bits_per_pixel / 8))) = 0x00FFFF00;
						l++;
					}
					k++;
				}
			}
		j++;
		}
			i++;
	}

} 

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// static void	display_2d_rays(t_game *game)
// {
// 	double		i;
// 	long double		step = 1;
// 	step /= 500;
// 	step *= 2;
// 	double		angle = M_PI/2/(2/step);
// 	t_img		*minimap;
	
// 	i = -1;
// 	(void)minimap;
// 	game->rayDirX = game->dirX;
// 	game->rayDirY = game->dirY;
// 	// minimap = create_2d_minimap(game);
// 	rotate_matrix(&game->rayDirX, &game->rayDirY, -1 / step * (angle));
// 	while (i <= 1)
// 	{
// 		// if (i < 0)
// 		// 	rotate_matrix(&game->rayDirX, &game->rayDirY, -0.02);
// 		// else if (i > 0)
// 		rotate_matrix(&game->rayDirX, &game->rayDirY, angle);
// 		double	rayX = game->x;
// 		double	rayY = game->y;
// 		// while (game->display->map[(int)(rayY / MAP_SIZE)][(int)(rayX / MAP_SIZE)] == '0')
// 		// {
// 		// 	rayX += game->rayDirX;
// 		// 	rayY += game->rayDirY;
// 		// 	// *(unsigned int *)(game->img->data + (int) ((int) rayY * game->img->size_line + (int) rayX * (game->img->bits_per_pixel / 8))) = create_trgb(255, 255, 255, 255);
// 		// 	// if (i >= 0 - (step+step) && i <= 0 + (step+step))
// 		// 	// 	*(unsigned int *)(game->img->data + (int) ((int) rayY * game->img->size_line + (int) rayX * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
// 		// 	// // mlx_pixel_put(game->display->mlx, game->display->win, rayX, rayY, 0x00FFFF00);
// 		// 	// *(unsigned int *)(minimap->data + ((int) rayX / 64 * minimap->size_line + (int) rayY / 64 * (minimap->bits_per_pixel / 8))) = 0x0000FF00;
// 		// 	// printf("rayX: %f, rayY: %f\n", rayX, rayY);
// 		// }
// 		i += step;
// 	}

	// int distance_from_player = cast_middle_ray(game);
	// double tangente = tan(45) * distance_from_player;
	// printf("tangente: %f\n", tangente);
	// mlx_put_image_to_window(game->display->mlx, game->display->win, minimap->img, 100, 100);
	// rotate_matrix(&game->dirX, &game->dirY, M_PI / 2);
	// cast_middle_ray(game);
	// rotate_matrix(&game->dirX, &game->dirY, -M_PI / 2);


// }

void	refresh_2d_screen(t_game *game)
{
	mlx_clear_window(game->display->mlx, game->display->win);
	draw_2d_map(game);
	draw_2d_player(game);
	// display_2d_rays(game);

}


#include "../../include/graphic.h"

static void draw_2d_player(t_game *game)
{
	for (int i = -3; i < 4; i++)
	{
		for (int j = -3; j < 4; j++)
		{
			mlx_pixel_put(game->display->mlx, game->display->win, game->x + i, game->y + j, 0x00FF0000);
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

	i = 0;
	size = MAP_SIZE;
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
						mlx_pixel_put(game->display->mlx, game->display->win, i * MAP_SIZE + l, j * MAP_SIZE + k, 0x00FFFFFF);
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

static void	display_2d_ray(t_game *game)
{
	double rayX = game->x;
	double rayY = game->y;
	while (game->display->map[(int)(rayX / MAP_SIZE)][(int)(rayY / MAP_SIZE)] == '0')
	{
		rayX += game->dirX;
		rayY += game->dirY;
		mlx_pixel_put(game->display->mlx, game->display->win, rayX, rayY, 0x00FFF000);
		// printf("rayX: %f, rayY: %f\n", rayX, rayY);
	}
}

void	refresh_2d_screen(t_game *game)
{
	mlx_clear_window(game->display->mlx, game->display->win);
	draw_2d_map(game);
	display_2d_ray(game);
	draw_2d_player(game);

}
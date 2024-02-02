
#include "../../include/graphic.h"

// void	ray_3d_display()

void	display_3d_map(t_game *game)
{
	int i;
	int j;
	int	k;
	int l;
	double rayX;
	double rayY;

	(void) i;
	(void) j;
	(void) k;
	(void) l;
	(void) rayX;
	(void) rayY;
	rayX = game->x;
	rayY = game->y;
	i = 0;

	
	// ray_3d_display(game, rayX, rayY);
	while (game->display->map[(int)(rayX / MAP_SIZE)][(int)(rayY / MAP_SIZE)] == '0')
	{
		rayX += game->dirX;
		rayY += game->dirY;
		// mlx_pixel_put(game->display->mlx, game->display->win, rayX, rayY, 0x00FFF000);
		
		i++;
	}

	l = i;
	while (i > -l)
	{
		j = l;
		while (j > -l)
		{
			// mlx_pixel_put(game->display->mlx, game->display->win, 640 + i, 450 + j, 0x00FFFFFF);
			j--;
		}
		i--;
	}
}

void	refresh_3d_screen(t_game *game)
{
	mlx_clear_window(game->display->mlx, game->display->win);

	display_3d_map(game);

}
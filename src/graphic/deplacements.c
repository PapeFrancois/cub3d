#include "../../include/graphic.h"

void	move(int x, int y, t_game *game)
{
	double oldX;
	double oldY;
	(void) x;
	(void) y;
	(void) game;
	if (y == 0)
		return ;
	oldX = game->x;
	oldY = game->y;
	game->x += game->dirX * y;
	game->y += game->dirY * y;
	if (game->display->map[(int)(game->x / MAP_SIZE)][(int)(oldY / MAP_SIZE)] == '1')
	{
		game->x = oldX;
	}
	else if (game->display->map[(int)(oldX / MAP_SIZE)][(int)(game->y / MAP_SIZE)] == '1')
	{
		game->y = oldY;
	}
	refresh_screen(game);
}

void	rotate_matrix(double *x, double *y, double angle)
{
	double oldX = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = oldX * sin(angle) + *y * cos(angle);
}

void	rotate(double x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (x == 0)
		return ;
	// printf("x: %f, y: %d\n", x, y);
	x /= 10;
	// printf("game->dirX: %f, game->dirY: %f\n", game->dirX, game->dirY);
	rotate_matrix(&game->dirX, &game->dirY, x);
	rotate_matrix(&game->planeX, &game->planeY, x);
	// printf("game->dirX: %f, game->dirY: %f\n", game->dirX, game->dirY);
	refresh_screen(game);
}
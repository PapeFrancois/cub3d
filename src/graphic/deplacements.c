#include "../../include/graphic.h"

void	move(double step, t_game *game)
{
	double oldX;
	double oldY;
	(void) step;
	(void) game;
	if (step == 0)
		return ;
	oldX = game->x;
	oldY = game->y;
	step /= 100;
	game->x += game->dirX * step;
	game->y += game->dirY * step;
	printf("game->x: %f, game->y: %f\n", game->x, game->y);
	printf("char at x: %c\n", game->display->map[(int)(game->y)][(int)(game->x)]);
	if (game->display->map[(int)(game->y)][(int)(oldX)] == '1')
	{
		game->y = oldY;
	}
	else if (game->display->map[(int)(oldY)][(int)(game->x)] == '1')
	{
		game->x = oldX;
	}
	else if (game->display->map[(int)(game->y)][(int)(game->x)] == '1')
	{
		game->x = oldX;
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

void	rotate(double angle, t_game *game)
{
	if (angle == 0)
		return ;
	// printf("angle: %f, y: %d\n", angle, y);
	angle /= 80;
	// printf("game->dirX: %f, game->dirY: %f\n", game->dirX, game->dirY);
	rotate_matrix(&game->dirX, &game->dirY, angle);
	rotate_matrix(&game->planeX, &game->planeY, angle);
	// printf("game->dirX: %f, game->dirY: %f\n", game->dirX, game->dirY);
	refresh_screen(game);
}
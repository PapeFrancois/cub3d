
#include "../../include/graphic.h"

// void	ray_3d_display()

t_img	*create_image(t_game *game, int width, int height)
{
	t_img *img_data;
	
	img_data = ft_calloc(1, sizeof(t_img));
	img_data->width = width;
	img_data->height = height;
	img_data->img = mlx_new_image(game->display->mlx, img_data->width, img_data->height);
	if (img_data->img == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	img_data->bits_per_pixel = 0;
	img_data->size_line = 0;
	img_data->endian = 0;
	img_data->data = (char *) mlx_get_data_addr(img_data->img, &img_data->bits_per_pixel, &img_data->size_line, &img_data->endian);
	return (img_data);
}

double	get_distance(t_game *game, double rayX, double rayY)
{

	long double distanceX;
	long double distanceY;
	
	if (rayX > (double) game->x)
		distanceX = rayX - (double) game->x;
	else
		distanceX = (double) game->x - rayX;
	distanceX *= distanceX;
	if (rayY > (double) game->y)
		distanceY = rayY - (double) game->y;
	else
		distanceY = (double) game->y - rayY;
	distanceY *= distanceY;
	return (sqrt(distanceX + distanceY));
	if (distanceX > distanceY)
		return (sqrt(distanceX));
	else
		return (sqrt(distanceY));
}

void	display_3d_map(t_game *game)
{
	double	j;
	double	k;
	double	l;
	double	rayX;
	double	rayY;
	long double	i;
	long double	step = 1;
	double		angle;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;

	(void) i;
	(void) j;
	(void) k;
	(void) l;
	(void) rayX;
	(void) rayY;
	

	i = -SCREEN_WIDTH/2;
	step /= SCREEN_WIDTH;
	step *= 2;
	angle = M_PI/2/(2/step);
	game->rayDirX = game->dirX;
	game->rayDirY = game->dirY;
	l = 0;
	double tmpangle = -M_PI/4;
	dirX = game->dirX;
	dirY = game->dirY;
	planeX = game->planeX;
	planeY = game->planeY;
	rotate_matrix(&dirX, &dirY, -M_PI/4);
	while (tmpangle <= M_PI/4)
	{
		double cameraX = 2 * l / (double)SCREEN_WIDTH - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		
		rayX = game->x;
		rayY = game->y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;
		(void) perpWallDist;

		double stepX;
		double stepY;
		double side;
		double steper = 0.01;
		if (rayDirX < 0)
		{
			stepX = -steper;
			sideDistX = (game->x - rayX) * deltaDistX;
		}
		else
		{
			stepX = steper;
			sideDistX = (rayX + 1.0 - game->x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -steper;
			sideDistY = (game->y - rayY) * deltaDistY;
		}
		else
		{
			stepY = steper;
			sideDistY = (rayY + 1.0 - game->y) * deltaDistY;
		}
		while (game->display->map[(int)(rayY)][(int)(rayX)] && game->display->map[(int)(rayY)][(int)(rayX)] == '0')
		{

			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				rayX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				rayY += stepY;
				side = 1;
			}
		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
      	double lineHeight = (SCREEN_HEIGHT / perpWallDist * 50);
		double drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		double drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;

		
		for(int y = drawStart; y < drawEnd; y++)
		{
			*(unsigned int *)(game->img->data + (int) (y * game->img->size_line + (int) l * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
		}

		rotate_matrix(&dirX, &dirY, M_PI / 2 / SCREEN_WIDTH);
		tmpangle += M_PI/2/SCREEN_WIDTH;
		l++;
	}
}

void	refresh_3d_screen(t_game *game)
{
	// mlx_clear_window(game->display->mlx, game->display->win);

	display_3d_map(game);

}
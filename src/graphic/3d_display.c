
#include "../../include/graphic.h"
#include <math.h>

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
	printf("bits_per_pixel: %d\n", img_data->bits_per_pixel);
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
	double		total_angle;

	(void) i;
	(void) j;
	(void) k;
	(void) l;
	(void) rayX;
	(void) rayY;
	
	i = -1;

	step /= SCREEN_WIDTH;
	step *= 2;
	angle = M_PI/2/(2/step);
	total_angle = -SCREEN_WIDTH/2;
	game->rayDirX = game->dirX;
	game->rayDirY = game->dirY;
	l = 0;
	rotate_matrix(&game->rayDirX, &game->rayDirY, -1 / step * (angle));
	while (i <= 1)
	{
		j = 0;
		rayX = game->x;
		rayY = game->y;
		while (game->display->map[(int)(rayY / MAP_SIZE)][(int)(rayX / MAP_SIZE)] == '0')
		{
			rayX += (game->rayDirX);
			rayY += (game->rayDirY);
			*(unsigned int *)(game->img->data + (int) ((int) rayY * game->img->size_line + (int) rayX * (game->img->bits_per_pixel / 8))) = 0xFFFFFFFF;
			if (i >= 0 - (step+step) && i <= 0 + (step+step))
				*(unsigned int *)(game->img->data + (int) ((int) rayY * game->img->size_line + (int) rayX * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
			// j += 1;
		}
		j = get_distance(game, rayX, rayY);
		
		long double distanceX;
		long double distanceY;
	
		if (rayX > (double) game->x)
			distanceX = rayX - (double) game->x;
		else
			distanceX = (double) game->x - rayX;
		// distanceX *= distanceX;
		if (rayY > (double) game->y)
			distanceY = rayY - (double) game->y;
		else
			distanceY = (double) game->y - rayY;

		// j = cos(total_angle) / j;
		double calc = SCREEN_HEIGHT/2;
		if (j != 0)
			calc /= (double) (j/10);
		for (k = 0; k < (double) calc; k++)
		{
			if (((k+SCREEN_HEIGHT/2-game->crouch) < SCREEN_HEIGHT && l < SCREEN_WIDTH &&  (k+SCREEN_HEIGHT/2-game->crouch) >= 0 && l >= 0) &&
				*(unsigned int *)(game->img->data + (int) ((k+SCREEN_HEIGHT/2-game->crouch) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) != 0xFFFFFFFF)
				*(unsigned int *)(game->img->data + (int) ((k+SCREEN_HEIGHT/2-game->crouch) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
			// *(unsigned int *)(game->img->data + (int) ((k+SCREEN_HEIGHT/2) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
			if (((SCREEN_HEIGHT/2-k-game->crouch) < SCREEN_HEIGHT && l < SCREEN_WIDTH && (SCREEN_HEIGHT/2-k-game->crouch) >= 0 && l >= 0) &&
				*(unsigned int *)(game->img->data + (int) ((SCREEN_HEIGHT/2-k-game->crouch) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) != 0xFFFFFFFF)
				*(unsigned int *)(game->img->data + (int) ((SCREEN_HEIGHT/2-k-game->crouch) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
		}
		rotate_matrix(&game->rayDirX, &game->rayDirY, angle);
		l++;
		if (i < 0)
			total_angle -= angle;
		else if (i > 0)
			total_angle += angle;
		i += step;
	}
}

void	refresh_3d_screen(t_game *game)
{
	// mlx_clear_window(game->display->mlx, game->display->win);

	display_3d_map(game);

}
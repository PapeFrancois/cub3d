
#include "../../include/graphic.h"
#include <math.h>

// void	ray_3d_display()

t_img	*create_image(t_game *game, int width, int height)
{
	t_img *img_data = ft_calloc(1, sizeof(t_img));
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
	// printf("img_data->img: %p\n", img_data->img);
	// printf("img_data->bits_per_pixel: %d\n", img_data->bits_per_pixel);
	// printf("img_data->size_line: %d\n", img_data->size_line);
	// printf("img_data->endian: %d\n", img_data->endian);
	// printf("img_data->width: %d\n", img_data->width);
	// printf("img_data->height: %d\n", img_data->height);
	// printf("img_data->data: %p\n", img_data->data);
	img_data->data = (char *) mlx_get_data_addr(img_data->img, &img_data->bits_per_pixel, &img_data->size_line, &img_data->endian);
	
	// for (int i = 0; i < 64; i++)
	// {
	// 	for (int j = 0; j < 64; j++)
	// 	{
	// 		if (i < 32)
	// 			*(unsigned int *)(img_data->data + (i * img_data->size_line + j * (img_data->bits_per_pixel / 8))) = 0x00FF0000;
	// 		else
	// 			*(unsigned int *)(img_data->data + (i * img_data->size_line + j * (img_data->bits_per_pixel / 8))) = 0x0000FF00;
	// 	}
	// }
	// mlx_put_image_to_window(game->display->mlx, game->display->win, img_data->img, 0, 0);
	return (img_data);
}

void	fill_img(t_img *img, int color)
{
	for (int i = 0; i < img->height; i++)
	{
		for (int j = 0; j < img->width; j++)
		{
			*(unsigned int *)(img->data + (i * img->size_line + j * (img->bits_per_pixel / 8))) = color;
		}
	}
}

void	display_3d_map(t_game *game)
{
	double	j;
	double	k;
	double	l;
	double	rayX;
	double	rayY;
	long double		i;
	long double		step = 1;
	step /= SCREEN_WIDTH;
	step *= 2;
	double		angle = M_PI/2/(2/step);

	(void) i;
	(void) j;
	(void) k;
	(void) l;
	(void) rayX;
	(void) rayY;
	
	i = -1;

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
			rayX += (game->rayDirX/20);
			rayY += (game->rayDirY/20);
			*(unsigned int *)(game->img->data + (int) ((int) rayY * game->img->size_line + (int) rayX * (game->img->bits_per_pixel / 8))) = 0xFFFFFFFF;
			if (i >= 0 - (step+step) && i <= 0 + (step+step))
				*(unsigned int *)(game->img->data + (int) ((int) rayY * game->img->size_line + (int) rayX * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
			// j += 1;
		}
		long double distanceX;
		if (rayX > (double) game->x)
			distanceX = rayX - (double) game->x;
		else
			distanceX = (double) game->x - rayX;
		distanceX *= distanceX;
		long double distanceY;
		if (rayY > (double) game->y)
			distanceY = rayY - (double) game->y;
		else
			distanceY = (double) game->y - rayY;
		distanceY *= distanceY;
		if (distanceX > distanceY)
			j = sqrt(distanceX);
		else
			j = sqrt(distanceY);
		double calc = SCREEN_HEIGHT/2;
		if (j != 0)
			calc /= (double) j;
		for (k = 0; k < (double) calc; k++)
		{
			if (k+(SCREEN_HEIGHT/2) < SCREEN_HEIGHT && l < SCREEN_WIDTH && k+(SCREEN_HEIGHT/2) > 0 && l > 0)
				*(unsigned int *)(game->img->data + (int) ((k+SCREEN_HEIGHT/2-game->crouch) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
			// *(unsigned int *)(game->img->data + (int) ((k+SCREEN_HEIGHT/2) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
			if (SCREEN_HEIGHT/2-k < SCREEN_HEIGHT && l < SCREEN_WIDTH && SCREEN_HEIGHT/2-k > 0 && l > 0)
				*(unsigned int *)(game->img->data + (int) ((SCREEN_HEIGHT/2-k-game->crouch) * game->img->size_line + (l) * (game->img->bits_per_pixel / 8))) = 0x00FF0000;
		}
		rotate_matrix(&game->rayDirX, &game->rayDirY, angle);
		l++;
		i += step;
	}
	// int distance_from_player = cast_middle_ray(game);
	// double tangente = tan(45) * distance_from_player;
	// (void)distance_from_player;
}

void	refresh_3d_screen(t_game *game)
{
	// mlx_clear_window(game->display->mlx, game->display->win);

	display_3d_map(game);

}
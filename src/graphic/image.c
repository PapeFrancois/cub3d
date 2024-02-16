#include "../../include/graphic.h"
#include "../../include/image.h"

void	init_images(t_mlx *mlx)
{
	mlx->wall = malloc(sizeof(t_img));
	mlx->wall->width = 640;
	mlx->wall->height = 640;
	mlx->wall->img = mlx_xpm_file_to_image(mlx->mlx, "./texture/wall.xpm", &mlx->wall->width, &mlx->wall->height);
	if (!mlx->wall->img)
	{
		printf("Error\n");
		exit(1);
	}
	printf("good\n");
	mlx->wall->data = mlx_get_data_addr(mlx->wall->img, &mlx->wall->bits_per_pixel, &mlx->wall->size_line, &mlx->wall->endian);
}

void	display_img(t_mlx *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, x, y);
}

void	display_deformed_img(t_mlx *mlx, t_img *img, int x, int y)
{
	int i;
	int j;
	(void) mlx;
	(void) x;
	(void) y;
	(void) img;
	(void) i;
	(void) j;
	

}
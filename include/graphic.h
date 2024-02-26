#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "cub3d.h"
# include "../minilibx-linux/mlx.h"
# include "../utils/blibft/printb.h"
# include <math.h>
# include "image.h"
# define MAP_SIZE 16
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		*img_north;
	t_img		*img_south;
	t_img		*img_west;
	t_img		*img_east;
	t_img		*wall;
}	t_mlx;

typedef struct s_game
{
	t_mlx		*display;
	double			x;
	double			y;
	t_img		*img;
	double		dirX;
	double		dirY;
	double		rayDirX;
	double		rayDirY;
	double		planeX;
	double		planeY;
	double			walking;
	double			rotate;
	int			crouch;
	int			running;
	int			display_mode;
}	t_game;

void	display();
void	free_2d_char(char **str);
void	refresh_2d_screen(t_game *game);
void	refresh_3d_screen(t_game *game);
void	init_images(t_mlx *mlx);
void	display_img(t_mlx *mlx, t_img *img, int x, int y);
void	display_deformed_img(t_mlx *mlx, t_img *img, int x, int y);

/* FUNCTIONS */
void	refresh_screen(t_game *game);
void	rotate(double angle, t_game *game);
void	rotate_matrix(double *x, double *y, double angle);
void	move(double step, t_game *game);
double cast_middle_ray(t_game *game);
t_img	*create_image(t_game *game, int width, int height);

#endif
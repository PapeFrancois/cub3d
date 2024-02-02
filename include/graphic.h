#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "cub3d.h"
# include "../minilibx-linux/mlx.h"
# include "../utils/libft/libft.h"
# include <math.h>
# include "image.h"
# define MAP_SIZE 20

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
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			walking;
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
void	rotate(double x, int y, t_game *game);
void	move(int x, int y, t_game *game);

#endif
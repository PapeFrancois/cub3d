#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "cub3d.h"
# include "../minilibx-linux/mlx.h"
# include "../utils/libft/libft.h"
# include <math.h>
# define PI 3.14159265358979323846
# define MAP_SIZE 20

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		**map;
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

#endif
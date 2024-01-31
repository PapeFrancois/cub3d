#include "../../include/graphic.h"

int	destroy_mlx(t_mlx *display)
{
	mlx_destroy_window(display->mlx, display->win);
	mlx_destroy_display(display->mlx);
	free_2d_char(display->map);
	free(display->mlx);
	exit(0);
}

void draw_2d_player(t_game *game)
{
	for (int i = -3; i < 4; i++)
	{
		for (int j = -3; j < 4; j++)
		{
			mlx_pixel_put(game->display->mlx, game->display->win, game->x + i, game->y + j, 0x00FF0000);
		}
	}
}

void	draw_2d_map(t_game *game)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		size;

	i = 0;
	size = MAP_SIZE;
	while (game->display->map[i])
	{
		j = 0;
		while (game->display->map[i][j])
		{
			if (game->display->map[i][j] == '1')
			{
				k = 0;
				while (k < size)
				{
					l = 0;
					while (l < size)
					{
						mlx_pixel_put(game->display->mlx, game->display->win, i * MAP_SIZE + l, j * MAP_SIZE + k, 0x00FFFFFF);
						l++;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}

}

void	display_2d_ray(t_game *game)
{
	double rayX = game->x;
	double rayY = game->y;
	while (game->display->map[(int)(rayX / MAP_SIZE)][(int)(rayY / MAP_SIZE)] == '0')
	{
		// printf("rayX / map_size : %i    rayY / map_size : %i\n", (int)(rayX / MAP_SIZE), (int)(rayY / MAP_SIZE));
		rayX += game->dirX;
		rayY += game->dirY;
		mlx_pixel_put(game->display->mlx, game->display->win, rayX, rayY, 0x00FFF000);
		// printf("rayX: %f, rayY: %f\n", rayX, rayY);
	}
}

void	refresh_2d_screen(t_game *game)
{
	mlx_clear_window(game->display->mlx, game->display->win);
	draw_2d_map(game);
	display_2d_ray(game);
	draw_2d_player(game);

}

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

	
	ray_3d_display(game, rayX, rayY);
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

void	refresh_screen(t_game *game)
{
	if (game->display_mode == 2)
		refresh_2d_screen(game);
	else if (game->display_mode == 3)
		refresh_3d_screen(game);
}

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
	// double oldPlaneX = game->planeX;
	// game->planeX = game->planeX * cos(-x) - game->planeY * sin(-x);
	// game->planeY = oldPlaneX * sin(-x) + game->planeY * cos(-x);
	// printf("game->dirX: %f, game->dirY: %f\n", game->dirX, game->dirY);
	refresh_screen(game);
}

int	key_hook(int keycode, t_game *game)
{
	int	speed;

	speed = 1;
	// game->walking = 1;
	if (keycode == 65307)
		destroy_mlx(game->display);
	else if (keycode == 119) //w
		game->walking = 1;
		// move(0, speed, game);
	else if (keycode == 97)  //a
		rotate(-speed, 0, game);
	else if (keycode == 115) //s
		game->walking = -1;
		// move(0, -speed, game);
	else if (keycode == 100) //d
		rotate(speed, 0, game);
	return (0);
}

char	**create_map()
{
	char	**map;
	
	map = ft_calloc(MAP_SIZE + 1, sizeof(char *));
	if (!map)
		return (NULL);
	for (int i = 0; i < MAP_SIZE; i++)
	{
		map[i] = ft_calloc(MAP_SIZE + 1, sizeof(char));
		if (!map[i])
			return (free_2d_char(map), NULL);
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1)
				map[i][j] = '1';
			else
				map[i][j] = '0';
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	map[10][11] = '1';
	map[15][3] = '1';
	return (map);
}

t_mlx	init_mlx()
{
	t_mlx	display;

	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, 1280, 900 , "covi3d");
	display.map = create_map();

	return (display);
}

t_game	init_game(t_mlx display)
{
	t_game	game;

	game.display = &display;
	game.x = 10 * MAP_SIZE;
	game.y = 10 * MAP_SIZE;
	game.dirX = 0;
	game.dirY = 1;
	game.planeX = 0;
	game.planeY = 0.66;
	game.display_mode = 2;
	game.walking = 0;

	return (game);
}

int	key_release_hook(int keycode, t_game *game)
{
	(void) keycode;
	(void) game;
	printf("keycode: %d\n", keycode);
	if (keycode == 119 || keycode == 115)
		game->walking = 0;
	return (0);
}

int	key_loop_hook(t_game *game)
{
	move(0, game->walking, game);
	return (0);
}

void	display()
{
	t_mlx	display;
	t_game	game;

	display = init_mlx();
	game = init_game(display);
	refresh_screen(&game);
	mlx_loop_hook(display.mlx, key_loop_hook, &game);
	mlx_hook(display.win, 17, 1L << 17, destroy_mlx, &game);
	mlx_hook(display.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(display.win, 3, 1L << 1, key_release_hook, &game);
	mlx_loop(display.mlx);
}
#include "../../include/graphic.h"


int	destroy_mlx(t_mlx *display)
{
	mlx_destroy_window(display->mlx, display->win);
	mlx_destroy_display(display->mlx);
	free_2d_char(display->map);
	free(display->mlx);
	exit(0);
}

void	refresh_screen(t_game *game)
{
	// mlx_clear_window(game->display->mlx, game->display->win);
	// create_image(game);
	// return ;
	game->img = create_image(game, SCREEN_WIDTH, SCREEN_HEIGHT);
	refresh_3d_screen(game);
	refresh_2d_screen(game);
	mlx_clear_window(game->display->mlx, game->display->win);
	mlx_put_image_to_window(game->display->mlx, game->display->win, game->img->img, 0, 0);
	mlx_destroy_image(game->display->mlx, game->img->img);

	free(game->img);
	// if (game->display_mode == 2)
	// else if (game->display_mode == 3)
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
		game->rotate = -1;
	else if (keycode == 115) //s
		game->walking = -1 ;
		// move(0, -speed, game);
	else if (keycode == 100) //d
		game->rotate = 1;
	else if (keycode == 65505)
		game->running = 3;
	else if (keycode == 65507)
		game->crouch = 100;
	return (0);
}

char	**create_map()
{
	char	**map;
	
	map = ft_calloc(MAP_SIZE + 10, sizeof(char *));
	if (!map)
		return (NULL);
	for (int i = 0; i < MAP_SIZE; i++)
	{
		map[i] = ft_calloc(MAP_SIZE + 10, sizeof(char));
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
	map[4][6] = '1';
	map[8][3] = '1';
	return (map);
}

t_mlx	init_mlx()
{
	t_mlx	display;

	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "covi3d");
	display.map = create_map();

	return (display);
}

t_game	init_game(t_mlx display)
{
	t_game	game;

	game.display = &display;
	game.x = 8 * MAP_SIZE;
	game.y = 8 * MAP_SIZE;
	game.dirX = 0;
	game.dirY = -1;
	game.display_mode = 3;
	game.walking = 0;
	game.crouch = 0;
	game.rotate = 0;
	game.running = 1;

	return (game);
}

int	key_release_hook(int keycode, t_game *game)
{
	(void) keycode;
	(void) game;
	if (keycode == 119 || keycode == 115)
		game->walking = 0;
	else if (keycode == 97 || keycode == 100)
		game->rotate = 0;
	else if (keycode == 65505)
		game->running = 1;
	else if (keycode == 65507)
		game->crouch = 0;
	return (0);
}

int	key_loop_hook(t_game *game)
{
	static int	tmp;
	move((double) (game->walking * game->running), game);
	rotate(game->rotate * game->running, game);
	if (game->crouch != tmp)
		refresh_screen(game);
	tmp = game->crouch;
	return (0);
}

void	display()
{
	t_mlx	display;
	t_game	game;

	display = init_mlx();
	game = init_game(display);
	// init_images(&display);
	if (game.display_mode == 3)
		init_images(game.display);
	for (int i = 0; display.map[i]; i++)
		printf("%s\n", display.map[i]);
	refresh_screen(&game);
	mlx_loop_hook(display.mlx, key_loop_hook, &game);
	mlx_hook(display.win, 17, 1L << 17, destroy_mlx, &game);
	mlx_hook(display.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(display.win, 3, 1L << 1, key_release_hook, &game);
	mlx_loop(display.mlx);
}
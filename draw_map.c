#include "long.h"

void	print_ec(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line] && game->map.map[line][col] == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit.img, x, y);
		mlx_string_put(game->mlx, game->win, x + 30, y + 40, 0x00FF00, "STEPS");
		mlx_string_put(game->mlx, game->win, x + 35, y + 60, 0x00FF00, "0");
	}
	if (game->map.map[line] && game->map.map[line][col] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.item.img, x + \
		20, y + 20);
	}
}

void	print_10p(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line] && game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall.img, x, y);
	if (game->map.map[line] && game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
	if (game->map.map[line] && game->map.map[line][col] == 'P')
	{
		game->map.player.y = y;
		game->map.player.x = x;
		mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
	}
	if (game->map.map[line] && game->map.map[line][col] == 'M')
	{
		game->zombis[game->zomb_count].zomb_x = x;
		game->zombis[game->zomb_count].zomb_y = y;
		game->zombis[game->zomb_count].direction = 1;
		if (game->zomb_count > 0)
		{
			game->zomb_count--;
		}
	}
}

void	draw_map(t_game *game)
{
	size_t	line;
	size_t	col;

	col = 0;
	line = 0;
	while (line <= game->map.line)
	{
		col = 0;
		while (col < game->map.colum)
		{
			print_10p(game, line, col);
			print_ec(game, line, col);
			col++;
		}
		line++;
	}
}

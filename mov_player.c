#include "long.h"

void	replace_image(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, \
							game->map.player.x, game->map.player.y);
}

void	reset_map_and_update_player_pos(t_game *game, int x, int y)
{
	game->map.map[game->map.player.y / 100][game->map.player.x / 100] = '0';
	game->map.map[y / 100][x / 100] = 'P';
	game->map.player.y = y;
	game->map.player.x = x ;
}

void	update_steps(t_game *game)
{
	char	*s;
	size_t	i;

	i = 0;
	if (game->collect_count == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit_open.img, \
		game->exit_x, game->exit_y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit.img, \
		game->exit_x, game->exit_y);
	mlx_string_put(game->mlx, game->win, game->exit_x + 30, \
				game->exit_y + 40, 0x00FF00, "STEPS");
	mlx_string_put(game->mlx, game->win, game->exit_x + 35, game->exit_y + 60, \
				0x00FF00, ft_itoa(++game->steps));
	s = ft_itoa(game->steps);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map.map[y / 100][x / 100] == 'M')
	{
		exit(0);
	}
	if (game->map.map[y / 100][x / 100] == 'E' && game->collect_count == 0)
	{
		replace_image(game, x, y);
		reset_map_and_update_player_pos(game, x, y);
		update_steps(game);
		exit(0);
	}
	else if (game->map.map[y / 100][x / 100] == 'C' )
	{
		replace_image(game, x, y);
		reset_map_and_update_player_pos(game, x, y);
		game->collect_count--;
		update_steps(game);
	}
	else if (game->map.map[y / 100][x / 100] == '0' \
			&& game->map.map[y / 100][x / 100] != '1')
	{
		replace_image(game, x, y);
		reset_map_and_update_player_pos(game, x, y);
		update_steps(game);
	}
}

int	action(int keycode, t_game *game)
{
	int	y;
	int	x;

	y = game->map.player.y ;
	x = game->map.player.x ;
	if (keycode == 2)
		move_player(game, x + TILES, y);
	if (keycode == 13)
		move_player(game, x, y - TILES);
	if (keycode == 0)
		move_player(game, x - TILES, y);
	if (keycode == 1)
		move_player(game, x, y + TILES);
	if (keycode == 53)
		exit(0);
	return (1);
}

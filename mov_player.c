/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:45:44 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/05 08:20:39 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	replace_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, \
							game->map.player.x, game->map.player.y);
}

void	reset_map_and_update_player_pos(t_game *game, int x, int y)
{
	game->map.map[game->map.player.y / TILES][game->map.player.x / TILES] = '0';
	game->map.map[y / TILES][x / TILES] = 'P';
	game->map.player.y = y;
	game->map.player.x = x ;
}

void	update_steps(t_game *game)
{
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
	game->steps_string = ft_itoa(++game->steps, game->steps_string, game);
	mlx_string_put(game->mlx, game->win, game->exit_x + 35, game->exit_y + 60, \
				0x00FF00, game->steps_string);
	while (game->steps_string[i])
	{
		write(1, &game->steps_string [i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map.map[y / TILES][x / TILES] == 'M')
	{
		game_end_success(game, "game over");
	}
	if (game->map.map[y / TILES][x / TILES] == 'E' && game->collect_count == 0)
	{
		replace_image(game);
		reset_map_and_update_player_pos(game, x, y);
		update_steps(game);
		game_end_success(game, "congratz, you made it");
	}
	else if (game->map.map[y / TILES][x / TILES] == 'C' )
	{
		replace_image(game);
		reset_map_and_update_player_pos(game, x, y);
		game->collect_count--;
		update_steps(game);
	}
	else if (game->map.map[y / TILES][x / TILES] == '0' \
			&& game->map.map[y / TILES][x / TILES] != '1')
	{
		replace_image(game);
		reset_map_and_update_player_pos(game, x, y);
		update_steps(game);
	}
}

int	action(int keycode, t_game *game)
{
	int		y;
	int		x;

	y = game->map.player.y ;
	x = game->map.player.x ;
	if (keycode == RIGHT)
		move_player(game, x + TILES, y);
	if (keycode == UP)
		move_player(game, x, y - TILES);
	if (keycode == LEFT)
		move_player(game, x - TILES, y);
	if (keycode == DOWN)
		move_player(game, x, y + TILES);
	if (keycode == 53)
		game_end_success(game, "game closed succesfully");
	return (0);
}

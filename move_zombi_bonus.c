/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_zombi_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:52:14 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/23 04:25:25 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_bonus.h"

void	move_if_exit(t_game *game, int xx, int yy, int i)
{
	if (game->map.map[yy / 100][xx / 100 - 1] == 'E' && game->zombis[i]. \
			direction == 1)
	{
		game->zombis[i].direction = 1;
	}
	if (game->map.map[yy / 100 ][xx / 100 + 1] == 'E' && game->zombis[i]. \
			direction == 1)
	{
		game->zombis[i].direction = 0;
	}				
	mlx_put_image_to_window(game->mlx, game->win, \
	game->img.emp.img, xx, yy);
	mlx_put_image_to_window(game->mlx, game->win, game->img.monster.img_m \
	[game->enemy_img_count], xx, yy);
}

void	initialize_zomb_cordintaes(t_game *game, int i)
{
	int	x;
	int	y;

	x = game->zombis[i].zomb_x;
	y = game->zombis[i].zomb_y;
	if (game->map.map[y / 100][x / 100 + 1] == 'P' && \
					game->zombis[i].direction == 1)
		game_end_success(game, "game over");
	if (game->map.map[y / 100][x / 100 - 1] == 'P' && \
					game->zombis[i].direction == 0)
		game_end_success(game, "game over");
	move_zombi(game, game->zomb_count, x, y);
	game->enemy_sprite_count = 0;
	game->zomb_count++;
}

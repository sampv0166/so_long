/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:48:14 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/16 05:08:23 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	replace_zombi_image(t_game *game, int x, int y, int i)
{
	if (game->zomb_count_save > 0)
	{
		game->map.map[y / 100][x / 100] = '0';
		game->map.map[y / 100][x / 100 + 1] = 'M';
		game->zombis[i].zomb_x = x + 100;
		game->zombis[i].zomb_y = y;
		if (game->map.map[y / 100 ][x / 100 + 2] && game->map.map[y / 100 ] \
		[x / 100 + 2] != '0' && game->map.map[y / 100 ][x / 100 + 2] != 'P')
		{
			game->zombis[i].direction = 0;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.monster.img_m[game->enemy_img_count], x + 100, y);
	}			
}

void	replace_zombi_image_back(t_game *game, int x, int y, int i)
{
	if (game->zomb_count_save > 0)
	{
		game->map.map[y / 100][x / 100] = '0';
		game->map.map[y / 100][x / 100 - 1] = 'M';
		game->zombis[i].zomb_x = x - 100;
		game->zombis[i].zomb_y = y;
		if (game->map.map[y / 100 ][x / 100 - 2] && game->map.map[y / 100 ] \
			[x / 100 - 2] != '0' && game->map.map[y / 100 ][x / 100 - 2] != 'P')
		{
			game->zombis[i].direction = 1;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.monster.img_m \
							[game->enemy_img_count], x - 100, y);
	}
}

void	move_zombi(t_game *game, int i)
{
	int	xx;
	int	yy;

	xx = game->zombis[i].zomb_x;
	yy = game->zombis[i].zomb_y;
	if (game->map.map[yy / 100 ][xx / 100 + 1] == 'P')
		exit(0);
	if (game->map.map[yy / 100 ][xx / 100 - 1] == 'P')
		exit(0);
	if (game->map.map[yy / 100 ][xx / 100 + 1] == '0' && \
		game->zombis[i].direction == 1 )
	{
		replace_zombi_image(game, xx, yy, i);
	}	
	else if (game->map.map[yy / 100 ][xx / 100 - 1] == '0' && \
			game->zombis[i].direction == 0)
	{
		replace_zombi_image_back(game, xx, yy, i);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map.map = get_map(&game, argc, argv);
	game.mlx = mlx_init();
	init_game(&game);
	game.win = mlx_new_window(game.mlx, game.map.colum \
	 * TILES, game.map.line * TILES, "so_long");
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, action, &game);
	mlx_loop_hook(game.mlx, init_sprites, &game);
	mlx_loop(game.mlx);
	return (0);
}

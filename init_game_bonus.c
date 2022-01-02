/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:45:44 by apila-va          #+#    #+#             */
/*   Updated: 2022/01/02 10:49:04 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_bonus.h"

int	init_enemy_sprites(t_game *game)
{
	int	i;

	game->zomb_count = 0;
	i = game->enemy_sprite_count;
	game->enemy_sprite_count++;
	if (i == 2000)
	{
		while (game->zomb_count < game->zomb_count_save)
		{
			initialize_zomb_cordintaes(game, game->zomb_count);
		}
		game->enemy_img_count++;
	}
	if (game->enemy_img_count == 3)
	{
		game->enemy_img_count = 0;
	}
	return (0);
}

// sprite count keeps track of when to replace  the image
// time in milliseconds
//

int	init_sprites(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = game->map.player.y;
	x = game->map.player.x;
	i = game->sprite_count;
	game->sprite_count++;
	if (i == 1200)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
		mlx_put_image_to_window(game->mlx, game->win, \
								game->img.player.img_p[game->img_count], x, y);
		game->sprite_count = 0;
		game->img_count++;
	}
	if (game->img_count == 10)
	{
		game->img_count = 0;
	}
	if (game->zomb_count_save > 0)
	{
		init_enemy_sprites(game);
	}
	return (0);
}

void	init_player_image(t_game *game)
{
	game->img.player.img_p[0] = mlx_xpm_file_to_image(game->mlx, PATH_P, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[1] = mlx_xpm_file_to_image(game->mlx, PATH_P2, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[2] = mlx_xpm_file_to_image(game->mlx, PATH_P3, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[3] = mlx_xpm_file_to_image(game->mlx, PATH_P4, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[4] = mlx_xpm_file_to_image(game->mlx, PATH_P5, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[5] = mlx_xpm_file_to_image(game->mlx, PATH_P6, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[6] = mlx_xpm_file_to_image(game->mlx, PATH_P7, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[7] = mlx_xpm_file_to_image(game->mlx, PATH_P7, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[8] = mlx_xpm_file_to_image(game->mlx, PATH_P8, \
	 			&game->img.player.size.x, &game->img.player.size.y);
	game->img.player.img_p[9] = mlx_xpm_file_to_image(game->mlx, PATH_P9, \
	 			&game->img.player.size.x, &game->img.player.size.y);
}

void	init_images(t_game *game)
{
	init_player_image(game);
	game->img.monster.img_m[0] = mlx_xpm_file_to_image(game->mlx, PATH_M1, \
	 			&game->img.monster.size.x, &game->img.monster.size.y);
	game->img.monster.img_m[1] = mlx_xpm_file_to_image(game->mlx, PATH_M2, \
	 			&game->img.monster.size.x, &game->img.monster.size.y);
	game->img.monster.img_m[2] = mlx_xpm_file_to_image(game->mlx, PATH_M3, \
	 			&game->img.monster.size.x, &game->img.monster.size.y);
	game->img.wall.img = mlx_xpm_file_to_image(game->mlx, PATH_W, \
				&game->img.wall.size.x, &game->img.wall.size.y);
	game->img.emp.img = mlx_xpm_file_to_image(game->mlx, PATH_E, \
				&game->img.emp.size.x, &game->img.emp.size.y);
	game->img.item.img = mlx_xpm_file_to_image(game->mlx, PATH_C, \
	 			&game->img.item.size.x, &game->img.item.size.y);
	game->img.exit.img = mlx_xpm_file_to_image(game->mlx, PATH_EX, \
				 &game->img.exit.size.x, &game->img.exit.size.y);
	game->img.exit_open.img = mlx_xpm_file_to_image(game->mlx, PATH_EX_OPEN, \
	 			&game->img.exit_open.size.x, &game->img.exit_open.size.y);
}

void	init_game(t_game *game)
{
	game->steps = 0;
	game->sprite_count = 0;
	game->img_count = 0;
	game->enemy_sprite_count = 0;
	game->enemy_img_count = 0;
	game->temp_map = NULL;
	game->zombis = malloc(sizeof(t_zomb) * game->zomb_count + 1);
	if (game->zombis == NULL)
		error(game, "error allocating memmory");
	game->zomb_count_save = game->zomb_count;
	if (game->zomb_count != 0)
		game->zomb_count = game->zomb_count - 1;
	init_images(game);
}

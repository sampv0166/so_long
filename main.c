/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:48:14 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/04 21:18:14 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	replace_zombi_image(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
	mlx_put_image_to_window(game->mlx, game->win, \
				game->img.monster.img_m[game->enemy_img_count], x + 100, y);
	game->map.map[y / 100][x / 100] = '0';
	game->map.map[y / 100][x / 100 + 1] = 'M';
	game->zombis[i].zomb_x = x + 100;
	game->zombis[i].zomb_y = y;
	if (game->map.map[y / 100 ][x / 100 + 2] && game->map.map[y / 100 ] \
	[x / 100 + 2] != '0' && game->map.map[y / 100 ][x / 100 + 2] != 'P')
	{
		game->zombis[i].direction = 0;
	}
}

void	replace_zombi_image_back(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.emp.img, x, y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.monster.img_m \
							[game->enemy_img_count], x - 100, y);
	game->map.map[y / 100][x / 100] = '0';
	game->map.map[y / 100][x / 100 - 1] = 'M';
	game->zombis[i].zomb_x = x - 100;
	game->zombis[i].zomb_y = y;
	if (game->map.map[y / 100 ][x / 100 - 2] && game->map.map[y / 100 ] \
		[x / 100 - 2] != '0' && game->map.map[y / 100 ][x / 100 - 2] != 'P')
	{
		game->zombis[i].direction = 1;
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

int	init_enemy_sprites(t_game *game)
{
	int	xx;
	int	yy;
	int	i;

	game->zomb_count = 0;
	i = game->enemy_sprite_count;
	game->enemy_sprite_count++;
	if (i == 3000)
	{
		while (game->zomb_count < game->zomb_count_save)
		{
			xx = game->zombis[game->zomb_count].zomb_x;
			yy = game->zombis[game->zomb_count].zomb_y;
			move_zombi(game, game->zomb_count);
			game->enemy_sprite_count = 0;
			game->zomb_count++;
		}
	}
	game->enemy_img_count++;
	if (game->enemy_img_count == 3)
	{
		game->enemy_img_count = 0;
	}
	return (0);
}

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
	}
	game->img_count++;
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

void	print_EC(t_game *game, int line, int col)
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

void	print_10P(t_game *game, int line, int col)
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
		printf("game over");
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

void init_player_image(t_game *game)
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

// initialize images

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

// draw the map

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
			print_10P(game, line, col);
			print_EC(game, line, col);
			col++;
		}
		line++;
	}
}

void init_game(t_game *game)
{
	game->steps = 0;
	game->sprite_count = 0;
	game->img_count = 0;
	game->enemy_sprite_count = 0;
	game->enemy_img_count = 0;
	game->zombis = malloc(sizeof(t_zomb) * game->zomb_count + 1);
	game->zomb_count_save = game->zomb_count + 1;
	game->zombis[game->zomb_count].zomb_x = 0;
	game->zombis[game->zomb_count].zomb_y = 0;
	if (!(game->zomb_count <= 0))
		game->zomb_count = game->zomb_count - 1;
	init_images(game);
}

int		main(void)
{
	t_game	game;

	game.map.map = get_map(&game);
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

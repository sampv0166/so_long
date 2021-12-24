/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:45:44 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/23 04:25:17 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_bonus.h"

int	check_for_newlines(char *map, t_game *game)
{
	size_t	col;
	size_t	row;

	row = 0;
	col = 0;
	while (row < game->map.line)
	{
		while (map[col++])
		{
			if (row == 0)
				game->map.colum = col;
			if (map[col] == '\n')
			{
				if (map[col + 1] == '\n')
					return (1);
				else
					break ;
			}
		}
		row++;
	}
	return (0);
}

void	set_row(char *map, t_game *game)
{
	size_t	col;
	size_t	row;
	size_t	i;

	col = 0;
	row = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			row++;
		i++;
	}
	game->map.line = row + 1;
}

int	square_check(t_game *game, char **og_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (og_map[i])
	{
		if (ft_strlen(og_map[i]) != game->map.colum)
			return (1);
		i++;
	}
	return (0);
}

int	walls_check(t_game *game, char **og_map)
{
	size_t	col;
	size_t	row;

	col = 0;
	row = 0;
	while (og_map && og_map[0] && og_map[0][col])
	{
		if (og_map[0][col] == '\n')
			break ;
		if (og_map[0][col] == '1' && og_map[game->map.line - 1][col] == '1')
			col++;
		else
			return (1);
	}
	while (og_map && og_map[row] && og_map[row][0])
	{
		if (og_map[row][0] != '1')
			return (1);
		if (og_map[row][game->map.colum - 1] != '1')
			return (1);
		row++;
	}
	return (0);
}

char	**get_map(t_game *game, int argc, char **argv)
{
	char	**og_map;
	size_t	fnl;

	if (argc <= 1)
		error(game, "not enough arguments");
	fnl = ft_strlen(argv[1]);
	if (argv[1][fnl - 1] != 'r' || argv[1][fnl - 2] != 'e' || \
		argv[1][fnl - 3] != 'b' || argv[1][fnl - 4] != '.')
	{
		error(game, "map file extension is wrong");
	}
	game->temp_map = read_file(game, 1, argv);
	if (!game->temp_map)
		error(game, "invalid map");
	set_row(game->temp_map, game);
	if (check_for_newlines(game->temp_map, game) > 0)
	{
		error(game, "invalid map");
	}
	og_map = ft_split(game->temp_map, '\n');
	if (!og_map)
		error(game, "somthing is wrong");
	if (square_check(game, og_map) || walls_check(game, og_map))
		error(game, "invalid map");
	return (og_map);
}

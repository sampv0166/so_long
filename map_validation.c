/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:45:44 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/16 07:17:33 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	check_for_newlines(char *map, t_game *game)
{
	size_t	col;
	size_t	row;

	col = 0;
	row = 0;
	while (map[col] && map[col] != '\n')
	{
		col++;
	}
	game->map.colum = col;
	if (map[col + 1] && map[col + 1] == '\n')
		return (1);
	return (0);
}

void	set_column_row(char *map, t_game *game)
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
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (og_map[j])
	{
		if (og_map[j][0] != '1')
			return (1);
		if (og_map[j][game->map.colum - 1] != '1')
			return (1);
		if (og_map[0][j] != '1')
			return (1);
		if (og_map[game->map.line - 1][j++] != '1')
			return (1);
		j++;
	}
	return (0);
}

char	**get_map(t_game *game, int argc, char **argv)
{
	char	*map;
	char	**og_map;
	size_t	fnl;

	if (argc <= 1)
		error();
	fnl = ft_strlen(argv[1]);
	if (argv[1][fnl - 1] != 'r' || argv[1][fnl - 2] != 'e' || \
		argv[1][fnl - 3] != 'b' || argv[1][fnl - 4] != '.')
	{
		error();
	}
	map = read_file(game, 1, argv);
	if (check_for_newlines(map, game) > 0)
	{
		error();
	}
	set_column_row(map, game);
	og_map = ft_split(map, '\n');
	if (square_check(game, og_map) || walls_check(game, og_map))
		error();
	return (og_map);
}

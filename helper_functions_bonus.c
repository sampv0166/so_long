/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:45:44 by apila-va          #+#    #+#             */
/*   Updated: 2022/01/02 11:07:06 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_bonus.h"

void	error(t_game *game, char *msg)
{
	int	i;

	if (game->steps_string)
		free_me(&game->steps_string);
	i = 0;
	while (game->map.map && game->map.map[i])
	{
		if (game->map.map[i])
			free_me(&game->map.map[i]);
		i++;
	}
	if (game->map.map)
		free_me(game->map.map);
	i = 0;
	if (game->zombis)
		free(game->zombis);
	if (game->temp_map && game->temp_map != NULL)
		free(game->temp_map);
	printf("Error\n%s", msg);
	exit(0);
}

void	free_me(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*allocate_memmory(char *s, t_game *game)
{
	s = (char *) malloc(sizeof(char ));
	if (!s)
		error(game, "error allocating memmory");
	*s = '\0';
	return (s);
}

void	game_end_success(t_game *game, char *msg)
{
	int	i;

	i = 0;
	if (game->steps_string)
		free_me(&game->steps_string);
	i = 0;
	while (game->map.map[i])
	{
		free_me(&game->map.map[i]);
		i++;
	}
	if (game->map.map)
		free_me(game->map.map);
	i = 0;
	if (game->zombis)
		free(game->zombis);
	if (game->temp_map)
		free_me(&game->temp_map);
	printf("%s", msg);
	exit(0);
}

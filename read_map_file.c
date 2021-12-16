/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:45:44 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/16 05:27:17 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	j;
	char	*new_string;

	i = 0;
	j = 0;
	if (!s1)
		s1 = allocate_memmory(s1);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *) malloc(sizeof(char) * total_len + 1);
	if (!new_string)
		return (NULL);
	while (s1 && s1[i])
		new_string[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	free_me(&s1);
	return (new_string);
}

size_t	count_map_letters(char *s, int c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			count++;
		i++;
	}
	return (count);
}

void	cep_check(t_game *game, char *map)
{
	game->collect_count = count_map_letters(map, 'C');
	if (count_map_letters(map, 'C') <= 0)
		error();
	if (count_map_letters(map, 'E') != 1)
		error();
	if (count_map_letters(map, 'P') != 1)
		error();
}

int	check_characters(char c)
{
	if (c == '0' || c == '1' || c == 'E' \
		|| c == 'C' || c == 'P' || c == '\n' \
		|| c == 'M')
	{
		return (1);
	}
	return (0);
}

char	*read_file(t_game *game, int i, char **argv)
{
	int		fd;
	char	*map;
	char	buffer[2];

	fd = open(argv[1], O_RDONLY);
	map = NULL;
	while (i > 0)
	{
		i = read (fd, buffer, 1);
		if (i > 0)
			buffer[1] = '\0';
		if (i == -1)
			error();
		if (i == 0)
			break ;
		if (buffer[0] == 'M')
			game->zomb_count++;
		if (check_characters(buffer[0]))
		{
			map = ft_strjoin(map, buffer);
		}
	}
	cep_check(game, map);
	return (map);
}

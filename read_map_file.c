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
	{
		s1 = malloc(sizeof(char));
		*s1 = '\0';
		if (!s1)
			return (NULL);
	}
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

char	*read_file(t_game *game, int i)
{
	int		fd;
	char	*map;
	char	buffer[2];

	fd = open("map.ber", O_RDONLY);
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
		if (buffer[0] == '0' || buffer[0] == '1' || buffer[0] == 'E' \
		|| buffer[0] == 'C' || buffer[0] == 'P' || buffer[0] == '\n' \
		|| buffer[0] == 'M')
		{
			map = ft_strjoin(map, buffer);
		}
	}
	cep_check(game, map);
	return (map);
}

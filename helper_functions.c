#include "long.h"

void	error(void)
{
	printf("map error");
	exit(0);
}

void	free_me(char **str)
{
	free(*str);
	*str = NULL;
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

char	*allocate_memmory(char *s)
{
	s = (char *) malloc(sizeof(char ));
	if (!s)
		exit(0);
	*s = '\0';
	return (s);
}

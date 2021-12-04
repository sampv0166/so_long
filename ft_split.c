#include"long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*ptr;

	if (!s || start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = malloc(sizeof (char) * len + 1);
	if (substr == NULL || s == NULL)
		return (NULL);
	ptr = substr;
	while (s[start] && len)
	{
		*substr = s[start];
		start++;
		len--;
		substr++;
	}
	*substr = '\0';
	return (ptr);
}

static size_t	ft_count(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
		}
		else if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			j++;
		}
	}
	return (j);
}

static	char	**ft_create_string(char **ptr, char const *s, char c \
				, size_t len)
{
	size_t	i;
	size_t	array_index;

	i = 0 ;
	array_index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				len++;
			}
			ptr[array_index++] = ft_substr(s, i - len, len);
			len = 0;
		}
		else
			i++;
	}
	ptr[array_index] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	first_array_length;
	size_t	string_length;

	string_length = 0;
	if (!s)
		return (0);
	first_array_length = ft_count(s, c);
	ptr = (char **)malloc (sizeof (char *) * first_array_length + 1);
	if (!ptr)
		return (0);
	if (first_array_length <= 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	ptr = ft_create_string(ptr, s, c, string_length);
	return (ptr);
}

#include "long.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)ptr + i) = x;
		i++;
	}
	return (ptr);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset (str, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memmory;

	memmory = (void *) malloc(size * count);
	if (memmory == NULL)
		return (NULL);
	ft_bzero(memmory, size * count);
	return (memmory);
}

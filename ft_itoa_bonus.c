/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:43:22 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/23 04:24:55 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_bonus.h"

static size_t	ft_find_len(long num)
{
	size_t	len;
	long	number;

	number = num;
	len = 0;
	if (number == 0)
		return (2);
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	if (num < 0)
		return (len + 2);
	return (len + 1);
}

static void	ft_itoa2(long number, char *ptr, size_t i, int n)
{
	while (number != 0)
	{
		ptr[i] = ((number % 10) + '0');
		number = number / 10;
		i--;
	}
	if (n == 0)
	{
		ptr[0] = '0';
	}
}

char	*ft_itoa(int n, char *s, t_game *game)
{
	size_t	array_length;
	char	*ptr;
	size_t	i;
	long	number;

	if (!s)
		allocate_memmory(s, game);
	number = n;
	array_length = ft_find_len(number);
	i = array_length - 1;
	ptr = (char *)malloc(sizeof(char) * array_length);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i = i - 1;
	if (number < 0)
	{
		ptr[0] = '-';
		number = number * -1;
	}
	ft_itoa2(number, ptr, i, n);
	free_me(&s);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:13:57 by groka             #+#    #+#             */
/*   Updated: 2023/01/29 22:47:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	sizeofstr(long n);
static void		fill(char *s, long n);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	long	num;

	num = n;
	size = sizeofstr(num);
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (str);
	if (num < 0)
	{
		*str = '-';
		fill(str + size - 2, -num);
	}
	else
		fill(str + size - 2, num);
	*(str + size - 1) = '\0';
	return (str);
}

static size_t	sizeofstr(long n)
{
	size_t	size;

	size = 2;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	fill(char *s, long n)
{
	*s = '0' + (n % 10);
	if (n / 10 > 0)
		fill(s - 1, n / 10);
}

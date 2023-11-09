/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:28:26 by groka             #+#    #+#             */
/*   Updated: 2023/10/11 02:35:04 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long long	sizeofstr(long long n);
static void			fill(char *s, long long n);

char	*ft_ltoa(long long n)
{
	char			*str;
	long long		size;
	long long		num;

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

static long long	sizeofstr(long long n)
{
	long long	size;

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

static void	fill(char *s, long long n)
{
	*s = '0' + (n % 10);
	if (n / 10 > 0)
		fill(s - 1, n / 10);
}

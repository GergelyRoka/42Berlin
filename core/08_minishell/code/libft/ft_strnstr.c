/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:04:04 by groka             #+#    #+#             */
/*   Updated: 2023/01/21 14:04:04 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			j;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	j = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (s1 + i + j && i + j < n)
		{
			if (s2[j] != s1[i + j])
				break ;
			++j;
			if (!(s2[j]))
				return ((char *)(s1 + i));
		}
		++i;
	}
	return (NULL);
}

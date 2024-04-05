/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:52:10 by groka             #+#    #+#             */
/*   Updated: 2023/01/15 10:52:10 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lengthofstr(char const *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = sizeof(char) * (lengthofstr(s1) + lengthofstr(s2) + 1);
	str = (char *)malloc(size);
	if (!(str))
		return (NULL);
	ft_bzero(str, size);
	ft_strlcat(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}

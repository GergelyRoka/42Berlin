/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:55:17 by groka             #+#    #+#             */
/*   Updated: 2023/01/21 13:55:17 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sizeofsubst(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	size;
	size_t	i;

	size = sizeofsubst(s, start, len);
	output = (char *)malloc(sizeof(char) * size);
	if (!output)
		return (output);
	i = 0;
	while (i < size - 1)
	{
		*(output + i) = *(s + start + i);
		++i;
	}
	*(output + i) = '\0';
	return (output);
}

static size_t	sizeofsubst(char const *s, unsigned int start, size_t len)
{
	size_t	sizeoftail;
	size_t	sizeofs;

	sizeofs = ft_strlen(s);
	if (sizeofs < start)
		return (1);
	sizeoftail = 0;
	while (len - sizeoftail && start + sizeoftail < sizeofs)
		++sizeoftail;
	return (sizeoftail + 1);
}

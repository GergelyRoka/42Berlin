/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:52:27 by groka             #+#    #+#             */
/*   Updated: 2023/01/14 22:52:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The strdup() function returns a pointer to a new string which is
       a duplicate of the string s.  Memory for the new string is
       obtained with malloc(3), and can be freed with free(3).*/
/*RETURN VALUE
       On success, the strdup() function returns a pointer to the
       duplicated string.  It returns NULL if insufficient memory was
       available, with errno set to indicate the error.*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s) + 1;
	copy = (char *)malloc(sizeof(char) * size);
	if (copy)
		ft_memcpy(copy, s, size);
	return (copy);
}

/*
char	*ft_strdup(const char *s)
{
	size_t		length;
	const char	*src;
	char		*out;

	if (s == NULL)
		return (NULL);
	src = s;
	length = 0;
	while (*src)
	{
		++src;
		++length;
	}
	out = malloc(sizeof(char) * (length + 1));
	if (out)
		ft_memcpy(out, s, length + 1);
	return (out);
}
*/
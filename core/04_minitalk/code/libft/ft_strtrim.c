/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:31:21 by groka             #+#    #+#             */
/*   Updated: 2023/01/16 17:31:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trimming_start(char const *s1, char const *set);
static size_t	trimming_end(char const *s1, char const *set, size_t start_i);
static int		isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	start_i;
	size_t	end_i;

	if (set == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return ((char *)malloc(0));
	start_i = trimming_start(s1, set);
	end_i = trimming_end(s1, set, start_i);
	if (*(s1 + start_i) == '\0')
	{
		string = (char *)malloc(sizeof(char) * 1);
		if (!string)
			return (string);
		*string = '\0';
		return (string);
	}
	string = (char *)malloc(sizeof(char) * (2 + end_i - start_i));
	if (!string)
		return (string);
	ft_strlcpy(string, s1 + start_i, sizeof(char) * (2 + end_i - start_i));
	return (string);
}

static size_t	trimming_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && isset(*(s1 + i), set))
		++i;
	return (i);
}

static size_t	trimming_end(char const *s1, char const *set, size_t start_i)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (start_i != i && isset(*(s1 + i), set))
		--i;
	return (i);
}

static int	isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

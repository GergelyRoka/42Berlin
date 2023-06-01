/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:34:15 by groka             #+#    #+#             */
/*   Updated: 2023/01/16 21:34:15 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					**ft_split(char const *s, char c);
static unsigned int		counting_words(char const *s, char c);
static char				**free_all(char **array);
static char				**splitting(char **a, char const *s, char c);
static void				fill(char const *str, char const *s, char *word);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;

	words = counting_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (words >= 0)
	{
		array[words] = NULL;
		words -= 1;
	}
	return (splitting(array, s, c));
}

static unsigned int	counting_words(char const *s, char c)
{
	unsigned int	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
			++words;
		while (*s && *s != c)
			++s;
	}
	return (words);
}

static char	**splitting(char **a, char const *s, char c)
{
	char const	*str;
	char		**array;
	int			i;

	array = a;
	i = 0;
	while (*s)
	{
		while (*s && c == *s && ++s)
			;
		if (*s && c != *s)
		{
			str = s;
			while (*s && c != *s && s++)
				;
			(*(a + i) = malloc(sizeof(char) * (s - str + 1)));
			if (!(*(a + i)))
				return (free_all(a));
			fill(str, s, a[i]);
			++i;
		}
	}
	return (array);
}

static char	**free_all(char **array)
{
	char	**a;

	a = array;
	while (*a)
	{
		free(*a);
		++a;
	}
	free(array);
	return (NULL);
}

static void	fill(char const *str, char const *s, char *word )
{
	while (str != s)
	{
		*word = *str;
		word++;
		str++;
	}
	*word = '\0';
}

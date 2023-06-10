/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:09 by groka             #+#    #+#             */
/*   Updated: 2023/02/24 15:10:38 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_ended(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (0);
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*join_output_substr(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[j])
		string[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	free(s1);
	free(s2);
	return (string);
}

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (length);
	while (*s++)
		++length;
	return (length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:02:17 by groka             #+#    #+#             */
/*   Updated: 2023/09/27 19:05:03 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*gnl_next_line(int fd, char *buffer, char *output);
static char	*gnl_buffer_grinder(char *buffer);
static int	is_ended(char *string);
static char	*join_output_substr(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;

	output = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (gnl_next_line(fd, buffer, output));
}

static char	*gnl_next_line(int fd, char *buffer, char *output)
{
	int	readc;

	if (output && is_ended(output))
		return (output);
	if (buffer[0] != 0)
	{
		output = join_output_substr(output, gnl_buffer_grinder(buffer));
		if (!output)
			return (NULL);
	}
	else
	{
		readc = read(fd, buffer, BUFFER_SIZE);
		if (readc == 0)
			return (output);
		if (readc < 0)
		{
			if (output)
				free(output);
			buffer[0] = 0;
			return (NULL);
		}
		buffer[readc] = '\0';
	}
	return (gnl_next_line(fd, buffer, output));
}

static char	*gnl_buffer_grinder(char *buffer)
{
	char	*substr;
	int		len;
	int		i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (substr);
	i = -1;
	while (++i < len)
		substr[i] = buffer[i];
	substr[i] = '\0';
	i = 0;
	while (i < BUFFER_SIZE - len)
	{
		buffer[i] = buffer[len + i];
		++i;
	}
	buffer[BUFFER_SIZE - len] = '\0';
	return (substr);
}

static int	is_ended(char *string)
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

static char	*join_output_substr(char *s1, char *s2)
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

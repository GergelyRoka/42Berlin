/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:12 by groka             #+#    #+#             */
/*   Updated: 2023/02/24 15:06:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;

	output = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (gnl_next_line(fd, buffer, output));
}

char	*gnl_next_line(int fd, char *buffer, char *output)
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

char	*gnl_buffer_grinder(char *buffer)
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

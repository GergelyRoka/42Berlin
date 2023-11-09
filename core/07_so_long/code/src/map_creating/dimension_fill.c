/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:38:50 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 05:41:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../lib/libft/libft.h"
#include "../../lib/libft/get_next_line.h"

void	dimension_fill(char *file)
{
	int		fd;
	char	*line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (line == NULL)
		error_msg_exit(ERRMSG_FILE_EMPTY);
	set_col(ft_strlen(line) - 1);
	while (line && ft_strcmp(line, "") != 0)
	{
		if (get_col() != ft_strlen(line) - 1)
		{
			free(line);
			close(fd);
			error_msg_exit(ERRMSG_FILE_FORMAT);
		}
		set_row(get_row() + 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

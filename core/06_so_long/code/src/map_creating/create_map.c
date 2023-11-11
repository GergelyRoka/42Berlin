/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:27:20 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 05:43:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../lib/libft/libft.h"
#include "../../lib/libft/get_next_line.h"

static void	alloc_memory(void);
static void	init_cell(int i, int j, char *line);

void	create_map(char	*file)
{
	int			fd;
	char		*line;
	size_t		i;
	size_t		j;

	fd = open_file(file);
	alloc_memory();
	line = get_next_line(fd);
	if (line == NULL)
		error_msg_exit(ERRMSG_FILE_READING);
	i = 0;
	while (line && ft_strcmp(line, "") != 0)
	{
		j = 0;
		while (j < get_col())
		{
			init_cell(i, j, line);
			++j;
		}
		++i;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static void	free_alloc_map(t_cell **map)
{
	size_t	i;

	i = 0;
	while (i < get_row())
	{
		free(map[i]);
		++i;
	}
	free(map);
}

static void	alloc_memory(void)
{
	t_cell	**map;
	size_t	i;

	map = ft_calloc(sizeof(t_cell *), get_row());
	if (map == NULL)
		error_msg_exit(ERRMSG_MALLOC);
	i = 0;
	while (i < get_row())
	{
		map[i] = ft_calloc(sizeof(t_cell), get_col());
		if (map[i] == NULL)
		{
			free_alloc_map(map);
			error_msg_exit(ERRMSG_MALLOC);
		}
		++i;
	}
	set_map(map);
}

static void	init_cell(int i, int j, char *line)
{
	char	c;

	c = line[j];
	if (c == '1')
		get_map()[i][j].type = 1;
	else if (c == '0')
		get_map()[i][j].type = 0;
	else if (c == 'P')
	{
		get_map()[i][j].player = true;
		set_player_pos(i, j);
	}
	else if (c == 'C')
		get_map()[i][j].collectable = true;
	else if (c == 'E')
		get_map()[i][j].exit = true;
	else
	{
		free(line);
		error_freemap_exit(ERRMSG_FILE_CHAR);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:00:41 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 20:00:59 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_map(t_cell **map)
{
	class_board(map, false);
}

t_cell	**get_map(void)
{
	return (class_board(NULL, false)->map);
}

void	free_map(void)
{
	size_t	i;

	i = 0;
	while (i < get_row())
	{
		free(get_map()[i]);
		++i;
	}
	free(get_map());
}

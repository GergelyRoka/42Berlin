/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:25:19 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:59:30 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

//initializing the map structure
t_board	*class_board(t_cell **map, t_boolean freeing)
{
	static t_board	board;

	if (freeing == true)
	{
		free_map();
		board.map = NULL;
		board.dim.col = 0;
		board.dim.row = 0;
	}
	if (map != NULL)
		board.map = map;
	return (&board);
}

void	destructor_of_board(void)
{
	class_board(NULL, true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:25:24 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 20:00:32 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_grid(size_t row, size_t col)
{
	class_board(NULL, false)->grid.row = row;
	class_board(NULL, false)->grid.col = col;
}

t_grid_size	get_grid(void)
{
	return (class_board(NULL, false)->grid);
}

t_coordinate	get_grid_start(void)
{
	return (class_board(NULL, false)->grid_start);
}

void	set_grid_start_i(int i)
{
	class_board(NULL, false)->grid_start.i = i;
}

void	set_grid_start_j(int j)
{
	class_board(NULL, false)->grid_start.j = j;
}

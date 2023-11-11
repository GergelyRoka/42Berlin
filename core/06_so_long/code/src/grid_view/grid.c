/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:43:41 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 20:34:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	grid(void)
{
	if (get_grid().col == get_col() && get_grid().row == get_row())
	{
		set_grid_start_i(0);
		set_grid_start_j(0);
		return ;
	}
	set_grid_start_i(get_player_pos().i - (get_grid().row / 2));
	set_grid_start_j(get_player_pos().j - (get_grid().col / 2));
	if (get_player_pos().i < get_grid().row / 2)
		set_grid_start_i(0);
	if (get_player_pos().j < get_grid().col / 2)
		set_grid_start_j(0);
	if (get_player_pos().i >= get_row() - (get_grid().row / 2))
		set_grid_start_i(get_row() - (get_grid().row));
	if (get_player_pos().j >= get_col() - (get_grid().col / 2))
		set_grid_start_j(get_col() - (get_grid().col));
}

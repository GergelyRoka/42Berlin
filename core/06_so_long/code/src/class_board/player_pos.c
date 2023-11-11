/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:00:14 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 20:00:14 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_player_pos(size_t i, size_t j)
{
	class_board(NULL, false)->player_coord.i = i;
	class_board(NULL, false)->player_coord.j = j;
}

t_coordinate	get_player_pos(void)
{
	return (class_board(NULL, false)->player_coord);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:41:17 by groka             #+#    #+#             */
/*   Updated: 2023/08/01 18:36:28 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS && is_it_finished())
	{
		mlx_close_window(get_mlx());
		return ;
	}
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(get_mlx());
		return ;
	}
	if (!is_it_finished())
	{
		if (keydata.key == MLX_KEY_W
			&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
			move_player(-1, 0);
		if (keydata.key == MLX_KEY_S 
			&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
			move_player(1, 0);
		if (keydata.key == MLX_KEY_A 
			&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
			move_player(0, -1);
		if (keydata.key == MLX_KEY_D
			&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
			move_player(0, 1);
	}
}

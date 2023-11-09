/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:44:56 by groka             #+#    #+#             */
/*   Updated: 2023/08/06 16:29:49 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../../include/so_long.h"

void	set_window(void)
{
	int32_t	width;
	int32_t	height;

	mlx_get_monitor_size(0, &width, &height);
	if ((int32_t)get_col() < width / WIDTH)
		width = get_col() * WIDTH;
	else
	{
		if (width / WIDTH / 2 == 0)
			width -= WIDTH;
	}
	if ((int32_t)get_row() < height * 9 / 10 / HEIGHT)
		height = get_row() * HEIGHT;
	else
	{
		height = height * 9 / 10 / HEIGHT * HEIGHT;
		if (height / HEIGHT / 2 == 0)
			height -= HEIGHT;
	}
	height = height / HEIGHT * HEIGHT;
	mlx_set_window_size(get_mlx(), width, height);
	mlx_set_window_limit(get_mlx(), width, height, width, height);
	mlx_get_window_pos(get_mlx(), 0, 0);
	set_grid(height / HEIGHT, width / WIDTH);
}

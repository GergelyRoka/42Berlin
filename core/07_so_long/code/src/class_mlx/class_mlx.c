/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:24:58 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:20:11 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	open_open_img(void);

mlx_t	*class_mlx(void)
{
	static mlx_t	*mlx;

	if (mlx == NULL)
	{
		mlx = mlx_init(1, 1, "so_long", true);
		if (!mlx)
			error_freemap_exit(ERROR_MSG_MLX_MALLOC);
		set_window();
	}
	return (mlx);
}

mlx_t	*get_mlx(void)
{
	return (class_mlx());
}

void	run_mlx(void)
{
	mlx_set_window_pos(get_mlx(), 0, 0);
	images_to_mlx();
	mlx_key_hook(get_mlx(), &keyhook, NULL);
	grid();
	view();
	open_open_img();
	mlx_loop(class_mlx());
	mlx_terminate(class_mlx());
}

static void	open_open_img(void)
{
	get_img_open()->instances[0].enabled = true;
	if (get_mlx()->height < get_img_open()->height)
		mlx_resize_image(get_img_open(), \
		(int)((float)get_mlx()->height / get_img_open()->height \
		* get_img_open()->width), get_mlx()->height);
	if (get_mlx()->width < get_img_open()->width)
		mlx_resize_image(get_img_open(), \
		get_mlx()->width, \
		(int)((float)get_mlx()->width / get_img_open()->width \
		* get_img_open()->height));
	if (get_mlx()->width > get_img_open()->width)
		get_img_open()->instances[0].x = \
		(get_mlx()->width - get_img_open()->width) / 2;
	if (get_mlx()->height > get_img_open()->height)
		get_img_open()->instances[0].y = \
		(get_mlx()->height - get_img_open()->height) / 2;
}

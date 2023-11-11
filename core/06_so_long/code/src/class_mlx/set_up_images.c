/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:07:57 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 04:34:10 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	textures_set_up(void);
static void	resize_images(void);
static void	instances_for_cell(int i, int j);
static void	extra_formats(void);

void	images_to_mlx(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	textures_set_up();
	resize_images();
	while (i < get_row())
	{
		j = 0;
		while (j < get_col())
		{
			instances_for_cell(i, j);
			++j;
		}
		++i;
	}
	extra_formats();
}

static void	textures_set_up(void)
{
	set_texture_wall(IMG_WALL_PATH);
	set_texture_path(IMG_PATH_PATH);
	set_texture_coll(IMG_COLL_PATH);
	set_texture_player(IMG_PLAYER_PATH);
	set_texture_exit(IMG_EXIT_PATH);
	set_texture_bg(IMG_BG_PATH);
	set_texture_open(IMG_OPEN_PATH);
	set_texture_end(IMG_END_PATH);
}

static void	resize_images(void)
{
	mlx_resize_image(get_img_wall(), WIDTH, HEIGHT);
	mlx_resize_image(get_img_path(), WIDTH - 20, HEIGHT - 20);
	mlx_resize_image(get_img_coll(), WIDTH + 40, HEIGHT + 60);
	mlx_resize_image(get_img_player(), 2 * WIDTH, 2 * HEIGHT);
	mlx_resize_image(get_img_exit(), 3 * WIDTH, 3 * HEIGHT * 1.5);
	mlx_resize_image(get_img_bg(), \
	get_img_bg()->width / 2, get_img_bg()->height / 2);
	mlx_resize_image(get_img_end(), \
	0.5 * get_img_end()->width, 0.5 * get_img_end()->height);
}

static void	instances_for_cell(int i, int j)
{
	t_cell	*cell;

	cell = &get_map()[i][j];
	if (get_map()[i][j].type == 1)
		cell->i_wall = new_instance_wall(j * HEIGHT, i * WIDTH);
	if (get_map()[i][j].type == 0)
		cell->i_path = new_instance_path(j * HEIGHT, i * WIDTH);
	if (get_map()[i][j].collectable == true)
		cell->i_coll = new_instance_coll(j * HEIGHT, i * WIDTH);
	if (get_map()[i][j].exit == true)
		cell->i_exit = new_instance_exit(j * HEIGHT, i * WIDTH);
	if (get_map()[i][j].player == true)
		cell->i_player = new_instance_player(j * HEIGHT, i * WIDTH);
}

static void	extra_formats(void)
{
	new_instance_bg(0, 0);
	new_instance_open(0, 0);
	new_instance_end(0, 0);
	get_img_end()->enabled = false;
}

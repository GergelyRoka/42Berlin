/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:43:53 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 03:41:24 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	hide_all_insta(void);
void	light_up_cell(int i, int j);

void	view(void)
{
	int	i;
	int	j;

	hide_all_insta();
	i = get_grid_start().i;
	while (i < get_grid_start().i + get_grid().row && i < get_row())
	{
		j = get_grid_start().j;
		while (j < get_grid_start().j + get_grid().col && j < get_col())
		{
			light_up_cell(i, j);
			++j;
		}
		++i;
	}
	get_img_bg()->instances[0].x = \
		- ((float)get_img_bg()->width / 2 - ((float)get_mlx()->width / 2)) \
		+ 3 * ((float)get_col() - get_grid_start().j - (float)get_grid().col \
		/ 2 - (float)get_col() / 2);
	get_img_bg()->instances[0].y = \
		- ((float)get_img_bg()->height / 2 - (float)get_mlx()->height / 2) \
		+ 3 * ((float)get_row() - get_grid_start().i - (float)get_row() / 2 \
		- (float)get_grid().row / 2);
}

void	hide_instas_img(mlx_image_t *img)
{
	int	i;

	i = 0;
	while (i < img->count)
	{
		img->instances[i].enabled = false;
		++i;
	}
}

void	hide_all_insta(void)
{
	hide_instas_img(get_img_coll());
	hide_instas_img(get_img_exit());
	hide_instas_img(get_img_wall());
	hide_instas_img(get_img_path());
	hide_instas_img(get_img_player());
	hide_instas_img(get_img_open());
}

void	light_up_cell(int i, int j)
{
	t_cell	*cell;

	cell = &get_map()[i][j];
	if (cell->type == 1)
		show_insta_img_wall(cell->i_wall, i - get_grid_start().i, \
		j - get_grid_start().j);
	if (cell->player)
		show_insta_img_player(cell->i_player, \
		i - get_grid_start().i, \
		j - get_grid_start().j);
	if (cell->exit && is_it_done())
		show_insta_img_exit(cell->i_exit, \
		i - get_grid_start().i, j - get_grid_start().j);
	if (cell->collectable)
		show_insta_img_coll(cell->i_coll, \
		i - get_grid_start().i, j - get_grid_start().j);
	if (cell->trail)
		show_insta_img_path(cell->i_path, \
		i - get_grid_start().i, j - get_grid_start().j);
}

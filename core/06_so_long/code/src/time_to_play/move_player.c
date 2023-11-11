/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:09:00 by groka             #+#    #+#             */
/*   Updated: 2023/08/01 18:34:40 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../lib/libft/libft.h"

static void	write_steps(int steps);
void		move_map(int x, int y);
static void	the_end(void);

void	move_player(int x, int y)
{
	int				new_x;
	int				new_y;
	static int		steps;
	char			str;

	new_x = get_player_pos().i + x;
	new_y = get_player_pos().j + y;
	if (get_map()[new_x][new_y].type == 0)
	{
		get_map()[get_player_pos().i][get_player_pos().j].player = false;
		get_map()[get_player_pos().i][get_player_pos().j].trail = true;
		set_player_pos(new_x, new_y);
		get_map()[new_x][new_y].player = true;
		if (get_map()[new_x][new_y].collectable)
			get_map()[new_x][new_y].collectable = false;
		if ((get_map()[new_x][new_y].exit) && is_it_done())
		{
			the_end();
			return ;
		}
		write_steps(++steps);
		grid();
		view();
	}
}

static void	write_steps(int steps)
{
	char	*str;

	str = ft_itoa(steps);
	write(1, "Steps: ", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void	change_coord(mlx_instance_t *insta, int x, int y)
{
	insta->x = insta->x - (y * WIDTH);
	insta->y = insta->y - (x * HEIGHT);
}

void	move_map(int x, int y)
{
	int	i;

	i = -1;
	while (++i < get_img_path()->count)
		change_coord(&((get_img_path()->instances)[i]), x, y);
	i = -1;
	while (++i < get_img_coll()->count)
		change_coord(&((get_img_coll()->instances)[i]), x, y);
	i = -1;
	while (++i < get_img_wall()->count)
		change_coord(&((get_img_wall()->instances)[i]), x, y);
	i = -1;
	while (++i < get_img_exit()->count)
		change_coord(&((get_img_exit()->instances)[i]), x, y);
}

static void	the_end(void)
{
	finish_it();
	hide_all_insta();
	get_img_end()->enabled = true;
	if (get_mlx()->width < get_img_end()->width)
		mlx_resize_image(get_img_end(), \
		get_mlx()->width, \
		(int)((float)(get_mlx()->width) / \
		get_img_end()->width * get_img_end()->height));
	if (get_mlx()->height < get_img_end()->height)
		mlx_resize_image(get_img_end(), \
		(int)((float)(get_mlx()->height) / \
		get_img_end()->height * get_img_end()->width), \
		get_mlx()->height);
	get_img_end()->instances[0].x = (float)get_mlx()->width / 2 \
	- (float)get_img_end()->width / 2;
	get_img_end()->instances[0].y = (float)get_mlx()->height / 2 \
	- (float)get_img_end()->height / 2;
	get_img_bg()->instances[0].x = \
	- ((float)get_img_bg()->width / 2 - ((float)get_mlx()->width / 2));
	get_img_bg()->instances[0].y = \
	- ((float)get_img_bg()->height / 2 - ((float)get_mlx()->height / 2));
}

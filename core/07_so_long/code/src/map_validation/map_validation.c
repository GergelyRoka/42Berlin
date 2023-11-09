/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:38:01 by groka             #+#    #+#             */
/*   Updated: 2023/08/06 16:20:55 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_boolean	is_walled(void);
static t_boolean	all_the_cool_things(void);
static t_boolean	all_roads_lead_to_rome(void);
static void			calculating_reachables(size_t x, size_t y);

t_boolean	map_validation(void)
{
	if (is_walled() == false)
		error_freemap_exit(ERROR_MSG_MAP_WALL);
	if (all_the_cool_things() == false)
		error_freemap_exit(ERRMSG_NO_ITEMS);
	if (all_roads_lead_to_rome() == false)
		error_freemap_exit(ERRMSG_ROADS);
	return (true);
}

static t_boolean	is_walled(void)
{
	size_t	index;

	index = 0;
	while (index < get_col())
	{
		if ((get_map()[0][index].type != 1)
			|| (get_map()[get_row() - 1][index].type != 1))
			return (false);
		++index;
	}
	index = 0;
	while (index < get_row())
	{
		if ((get_map()[index][0].type != 1)
			|| (get_map()[index][get_col() - 1].type != 1))
			return (false);
		++index;
	}
	return (true);
}

static t_boolean	all_the_cool_things(void)
{
	static size_t	sum_player;
	static size_t	sum_exit;
	static size_t	sum_collectables;
	static size_t	i;
	static size_t	j;

	while (i < get_row())
	{
		j = 0;
		while (j < get_col())
		{
			if (get_map()[i][j].player)
				++sum_player;
			if (get_map()[i][j].exit)
				++sum_exit;
			if (get_map()[i][j].collectable)
				++sum_collectables;
			++j;
		}
		++i;
	}
	return (sum_player == 1 && sum_exit == 1 && sum_collectables > 0);
}

static t_boolean	all_roads_lead_to_rome(void)
{
	size_t	i;
	size_t	j;

	calculating_reachables(get_player_pos().i, get_player_pos().j);
	i = 0;
	while (i < get_row())
	{
		j = 0;
		while (j < get_col())
		{
			if ((get_map()[i][j].exit
				|| get_map()[i][j].collectable)
				&& !get_map()[i][j].reachable)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

static void	calculating_reachables(size_t x, size_t y)
{
	if (x >= get_row() || y >= get_col()
		|| get_map()[x][y].type != 0 || get_map()[x][y].reachable)
		return ;
	get_map()[x][y].reachable = true;
	calculating_reachables(x + 1, y);
	if (x > 0)
		calculating_reachables(x - 1, y);
	calculating_reachables(x, y + 1);
	if (y > 0)
		calculating_reachables(x, y - 1);
}

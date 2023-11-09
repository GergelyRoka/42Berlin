/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_done.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:14:12 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 22:25:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_boolean	is_it_done(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < get_row())
	{
		j = 0;
		while (j < get_col())
		{
			if (get_map()[i][j].collectable)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

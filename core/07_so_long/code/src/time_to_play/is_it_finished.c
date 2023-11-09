/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_finished.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:21:57 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 22:26:35 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_boolean	finale(t_boolean end)
{
	static t_boolean	finished;

	if (end)
		finished = true;
	return (finished);
}

void	finish_it(void)
{
	finale(true);
}

t_boolean	is_it_finished(void)
{
	return (finale(false));
}

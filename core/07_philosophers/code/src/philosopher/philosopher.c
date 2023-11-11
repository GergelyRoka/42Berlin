/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:54:25 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 10:42:44 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*life_of_philosopher(void *attr)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)attr;
	while (true)
	{
		if (!do_think(philosopher))
			return (NULL);
		if (do_print(philosopher, none, 0) == false)
			return (NULL);
		if (!do_eat(philosopher))
			return (NULL);
		usleep(200);
		if (do_print(philosopher, none, 0) == false)
			return (NULL);
		if (!do_sleep(philosopher))
			return (NULL);
		usleep(200);
		if (do_print(philosopher, none, 0) == false)
			return (NULL);
	}
	return (NULL);
}

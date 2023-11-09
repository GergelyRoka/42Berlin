/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:29:30 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:29:49 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

// dev note
// maybe there are problems with timing
// maybe too much timing call / unnecessary

int	take_first_fork(t_philo *philosopher, t_fork *first);
int	take_second_fork(t_philo *philosopher, t_fork *second);
int	is_happy(t_fork *fork);
int	core_of_thougths(t_philo *philosopher);

int	do_think(t_philo *philosopher)
{
	int	status;

	while (true)
	{
		if (!do_print(philosopher, thinking, 0))
			return (false);
		status = core_of_thougths(philosopher);
		if (status == false)
			return (status);
		if (status == 1)
			return (true);
		if (timing(philosopher, thinking) == false)
			return (false);
	}
}

int	take_first_fork(t_philo *philosopher, t_fork *first)
{
	while (true)
	{
		if (is_happy(first))
			return (do_print(philosopher, forking, 0));
		if (timing(philosopher, thinking) == false)
			return (false);
	}
}

int	take_second_fork(t_philo *philosopher, t_fork *second)
{
	while (!is_happy(second))
	{
		if (timing(philosopher, trying) == false)
			return (false);
	}
	return (do_print(philosopher, forking, 0));
}

int	is_happy(t_fork *fork)
{
	int	happy;

	happy = false;
	pthread_mutex_lock(&fork->mutex);
	if (fork->is_free)
	{
		fork->is_free = false;
		happy = true;
	}
	pthread_mutex_unlock(&fork->mutex);
	return (happy);
}

int	core_of_thougths(t_philo *philosopher)
{
	int	status;

	if (philosopher->id % 2 == 0)
	{
		status = take_first_fork(philosopher, philosopher->left_fork);
		if (status)
			status = take_second_fork(philosopher, philosopher->right_fork);
	}
	else
	{
		status = take_first_fork(philosopher, philosopher->right_fork);
		if (status)
			status = take_second_fork(philosopher, philosopher->left_fork);
	}
	return (status);
}

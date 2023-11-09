/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:45:21 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 10:52:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	release_the_forks(t_philo *phil);

int	do_eat(t_philo *phil)
{
	if (gettimeofday(&phil->meal_time, NULL) != 0)
		return (false);
	phil->last_meal = progress_time(phil);
	if (!do_print(phil, eating, 0))
		return (false);
	if (timing(phil, eating) == false)
	{
		release_the_forks(phil);
		return (false);
	}
	release_the_forks(phil);
	if (phil->full_meals)
		phil->number_of_meals++;
	if (phil->full_meals > -1 && phil->full_meals == phil->number_of_meals)
	{
		if (!do_print(phil, none, 1))
			return (false);
	}
	return (true);
}

void	release_the_forks(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	philosopher->left_fork->is_free = true;
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	philosopher->right_fork->is_free = true;
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
}

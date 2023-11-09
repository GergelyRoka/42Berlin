/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:35:23 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:22:04 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	number_of_philo(int num);
int	printing(int time, int id, int activity, int finished);

int	do_print(t_philo *philo, int activity, int finished)
{
	int	flow;
	int	time;

	time = progress_time(philo);
	pthread_mutex_lock(philo->write_mutex);
	flow = printing(time, philo->id, activity, finished);
	pthread_mutex_unlock(philo->write_mutex);
	return (flow);
}
/*
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
*/

/**
 * @param time	time in ms
 * @param id	id of philosopher
 * @param activity	activity of philosopher
 * @param finished	1 if a philosophers ate enough, otherwise 0
*/
int	printing(int time, int id, int activity, int finished)
{
	static int	finishes = 0;
	static int	dead = 1;

	if (finished)
		finishes++;
	if (dead == 0 || finishes >= number_of_philo(0))
		return (false);
	if (activity == dying)
	{
		dead = 0;
		printf("%i %i died\n", time, id);
		return (false);
	}
	else if (activity == forking)
		printf("%i %i has taken a fork\n", time, id);
	else if (activity == thinking)
		printf("%i %i is thinking\n", time, id);
	else if (activity == eating)
		printf("%i %i is eating\n", time, id);
	else if (activity == sleeping)
		printf("%i %i is sleeping\n", time, id);
	return (true);
}

/**
 * @brief setting/getting the number of philos for the printing function
 * 
 * @param num 
 * @return int 
 */
int	number_of_philo(int num)
{
	static int	number_of_philos;

	if (num > 0)
		number_of_philos = num;
	return (number_of_philos);
}

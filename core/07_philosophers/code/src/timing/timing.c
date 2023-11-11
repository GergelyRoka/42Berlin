/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:51:32 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 10:11:47 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int			timing(t_philo *philo, int activity);
long long	get_us(t_philo *philo, int activity);
int			progress_time(t_philo *philo);
int			is_dead(t_philo *philo);
int			get_session_time(t_philo *philo, int activity);

int	timing(t_philo *philo, int activity)
{
	long long	us;
	int			session_time;

	us = get_us(philo, activity);
	session_time = get_session_time(philo, activity);
	while (us > 0)
	{
		if (progress_time(philo) > philo->time_to_die + philo->last_meal)
			return (do_print(philo, dying, 0));
		if (session_time)
			if (session_time <= progress_time(philo))
				return (true);
		usleep(50);
		us = us - 50;
	}
	return (true);
}

/**
 * @brief 
 * 
 * @param philo 
 * @return int -1 error 
 */
int	progress_time(t_philo *philo)
{
	struct timeval	current;
	int				sec;
	int				ms;
	int				round;

	round = 0;
	if (gettimeofday(&current, NULL) != 0)
		return (-1);
	sec = current.tv_sec - philo->start_time.tv_sec;
	ms = current.tv_usec - philo->start_time.tv_usec;
	if (ms % 1000 >= 500)
		round = 1;
	return (sec * 1000 + ms / 1000 + round);
}

long long	get_us(t_philo *philo, int activity)
{
	if (activity == eating)
		return (philo->time_to_eat * 1000);
	if (activity == sleeping)
		return (philo->time_to_sleep * 1000);
	if (activity == waiting)
		return (50);
	if (activity == thinking)
		return (10);
	if (activity == trying)
		return (10);
	return (10);
}

int	get_session_time(t_philo *philo, int activity)
{
	if (activity == sleeping)
		return (progress_time(philo) + philo->time_to_sleep);
	if (activity == eating)
		return (progress_time(philo) + philo->time_to_eat);
	return (0);
}

int	is_dead(t_philo *philo)
{
	struct timeval	current;
	long long		time;

	if (gettimeofday(&current, NULL) != 0)
		return (-1);
	time = (current.tv_sec - philo->meal_time.tv_sec) * 1000 - \
	(current.tv_usec - philo->meal_time.tv_usec) / 1000;
	if (time > philo->time_to_die)
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:41:33 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 06:41:22 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	fill_philos(t_data *data);

int	create_philosophers(t_data *data)
{
	int		n;

	n = data->number_of_philos;
	data->array_of_philos = malloc(sizeof(t_philo) * n);
	if (data->array_of_philos == NULL)
		return (false);
	fill_philos(data);
	return (true);
}

static void	fill_philos(t_data *data)
{
	int		i;
	t_philo	*philo_pointer;
	int		n;

	i = 0;
	n = data->number_of_philos;
	while (i < n)
	{
		philo_pointer = &(data->array_of_philos[i]);
		philo_pointer->id = i + 1;
		philo_pointer->time_to_die = data->time_to_die;
		philo_pointer->time_to_eat = data->time_to_eat;
		philo_pointer->time_to_sleep = data->time_to_sleep;
		philo_pointer->number_of_meals = 0;
		philo_pointer->full_meals = data->full_meals;
		philo_pointer->left_fork = &(data->array_of_forks[i]);
		philo_pointer->right_fork = &(data->array_of_forks[(i + 1) % n]);
		philo_pointer->write_mutex = &data->write_mutex;
		philo_pointer->start_time = data->start_time;
		philo_pointer->meal_time = data->start_time;
		philo_pointer->last_meal = 0;
		++i;
	}
}

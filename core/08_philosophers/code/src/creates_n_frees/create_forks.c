/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:08:05 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:37:41 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * @brief Create a forks object
 * 
 * @param n 
 * @return t_fork* 
 * 
 * 
 * @todo error exit call
 */
int	create_forks(t_data *data)
{
	int		i;
	int		n;

	n = data->number_of_philos;
	data->array_of_forks = malloc(sizeof(t_fork) * n);
	if (data->array_of_forks == NULL)
		return (false);
	i = 0;
	while (i < n)
	{
		data->array_of_forks[i].is_free = true;
		if (pthread_mutex_init(&(data->array_of_forks[i].mutex), NULL))
			return (false);
		++i;
	}
	return (true);
}

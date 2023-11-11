/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:30:40 by groka             #+#    #+#             */
/*   Updated: 2023/09/05 20:39:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	free_forks(t_data *data)
{
	int	i;
	int	error;
	int	error_buffer;
	int	n;

	i = 0;
	error = 0;
	n = data->number_of_philos;
	while (i < n)
	{
		error_buffer = pthread_mutex_destroy(&(data->array_of_forks[i].mutex));
		if (error_buffer != 0)
			error = error_buffer;
		++i;
	}
	free(data->array_of_forks);
	data->array_of_forks = NULL;
	if (error)
		return (false);
	return (true);
}

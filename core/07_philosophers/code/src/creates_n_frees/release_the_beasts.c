/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_the_beasts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:18:24 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:28:50 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	release_the_beasts(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_create(&data->threads[i], NULL, life_of_philosopher, \
		&data->array_of_philos[i]);
		++i;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(data->threads[i], NULL);
		++i;
	}
	return (true);
}

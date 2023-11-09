/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:10:16 by groka             #+#    #+#             */
/*   Updated: 2023/09/05 22:12:39 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	create_threads(t_data *data)
{
	data->threads = malloc(data->number_of_philos * sizeof(pthread_t));
	if (data->threads == NULL)
		return (false);
	return (true);
}

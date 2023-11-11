/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:43:08 by groka             #+#    #+#             */
/*   Updated: 2023/09/05 21:10:37 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	free_philosophers(t_data *data)
{
	free(data->array_of_philos);
	data->array_of_philos = NULL;
	return (true);
}

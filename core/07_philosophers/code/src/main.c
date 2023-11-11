/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:53:58 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:36:40 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (argumentum(ac, av, &data) == false)
		return (0);
	pthread_mutex_init(&data.write_mutex, NULL);
	if (gettimeofday(&data.start_time, NULL))
		NULL;
	creation(&data);
	release_the_beasts(&data);
	free_everything(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:45:23 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 10:49:04 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	do_sleep(t_philo *philosopher)
{
	if (!do_print(philosopher, sleeping, 0))
		return (false);
	return (timing(philosopher, sleeping));
}

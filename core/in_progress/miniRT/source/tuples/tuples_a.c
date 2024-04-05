/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:38:19 by groka             #+#    #+#             */
/*   Updated: 2024/03/26 15:43:08 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/tuples.h"

t_tuple	do_point(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 1});
}

t_tuple	do_vector(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 0});
}

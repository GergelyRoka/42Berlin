/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:57:37 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 03:48:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief	Rotating the ordered stack a until it is sorted.
 * 			Top node is the smallest integer.
 * 
 * @param a Stack a.
 */
void	finish_a(t_node **a)
{
	t_node	*min_node;

	min_node = min_node_in_stack(*a);
	if (dist_w_rot(min_node) < dist_w_rev_rot(min_node))
		while (min_node->title != head)
			do_ra(a);
	else
		while (min_node->title != head)
			do_rra(a);
}

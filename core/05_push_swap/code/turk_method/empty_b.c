/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:01:47 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:36:17 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief Push each node of stack b to stack a maintaining the ascending order.
 * 
 * @param a Stack a.
 * @param b Stack b.
 */
void	empty_b(t_node **a, t_node **b)
{
	t_node	*max_node_b;
	t_node	*new_pos_on_a;

	if (*b == NULL)
		return ;
	max_node_b = max_node_in_stack(*b);
	if (dist_w_rot(max_node_b) > dist_w_rev_rot(max_node_b))
		while (max_node_b->title != head)
			do_rrb(b);
	else
		while (max_node_b->title != head)
			do_rb(b);
	while (*b)
	{
		new_pos_on_a = node_new_pos_a(*a, *b);
		if (dist_w_rot(new_pos_on_a) < dist_w_rev_rot(new_pos_on_a))
			while (new_pos_on_a != *a)
				do_ra(a);
		else
			while (new_pos_on_a != *a)
				do_rra(a);
		do_pa(a, b);
	}
}

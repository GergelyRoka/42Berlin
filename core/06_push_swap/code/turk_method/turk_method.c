/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:35 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 16:08:52 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static void	empty_b(t_node **a, t_node **b);
static void	finish_a(t_node **a);

/**
 * @brief https://medium.com/@ayogun/push-swap-c1f5d2d41e97
 * 
 * @param a Stack A
 * @param b Stack B
 */
void	turk_method(t_node **a, t_node **b)
{
	while (size_of_stack(*a) > 5 && !is_a_ordered(*a))
		push_from_a_to_b(a, b);
	if (size_of_stack(*a) == 5 && !is_a_ordered(*a))
		ft_five_nums(a, b);
	empty_b(a, b);
	finish_a(a);
}

static void	empty_b(t_node **a, t_node **b)
{
	t_node	*max_node_b;
	t_node	*new_pos_on_a;

	if (*b == NULL)
		return ;
	max_node_b = max_node_in_stack(*b);
	if (dist_w_rot(max_node_b) > dist_w_rev_rot(max_node_b))
		while(max_node_b->title != head)
			do_rrb(b);
	else
		while(max_node_b->title != head)
			do_rb(b);
	while(*b)
	{
		new_pos_on_a = node_new_pos_a(*a, *b);
		if (dist_w_rot(new_pos_on_a) < dist_w_rev_rot(new_pos_on_a))
			while(new_pos_on_a != *a)
				do_ra(a);
		else
			while(new_pos_on_a != *a)
				do_rra(a);
		do_pa(a, b);
	}
}

static void	finish_a(t_node **a)
{
	t_node * min_node;
	
	min_node = min_node_in_stack(*a);
	if (dist_w_rot(min_node) < dist_w_rev_rot(min_node))
		while(min_node->title != head)
			do_ra(a);
	else
		while(min_node->title != head)
			do_rra(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_in_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:20 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 03:53:26 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static t_node	*mid_pos_in_stack_a(t_node *stack, t_node *node);

/**
 * @brief Looking for the position of a new node for stack a.
 * 
 * @param a			Stack a.
 * @param node		Moving node from stack b.
 * @return t_node*	The position, the new next node of the moving node.
 */
t_node	*node_new_pos_a(t_node *a, t_node *node)
{
	t_node	*min_node;
	t_node	*max_node;

	if (!node)
		return (a);
	if (a == NULL)
		return (a);
	if (a == (a)->next)
		return (a);
	min_node = min_node_in_stack(a);
	max_node = max_node_in_stack(a);
	if (min_node->value > node->value)
		return (min_node);
	if (max_node->value < node->value)
		return (min_node);
	return (mid_pos_in_stack_a(a, node));
}

/**
 * @brief	Looking for the position for the new node from stack b,
 * 			when it won't be the smallest nor greatest number of stack a.
 * 
 * @param stack Stack a.
 * @param node Moving node from stack b.
 * @return t_node* The position, the new next node of the moving node.
 */
static t_node	*mid_pos_in_stack_a(t_node *stack, t_node *node)
{
	while (!(stack->value > node->value
			&& stack->prev->value < node->value))
		stack = stack->prev;
	return (stack);
}

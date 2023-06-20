/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:22:25 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 01:50:45 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

/**
 * @brief Destroy the stack! Free all items!
 * 
 * @param stack 
 */
void	free_stack(t_node **stack)
{
	t_node	*node;

	if ((*stack) == NULL)
		return ;
	(*stack)->prev->next = NULL;
	while (*stack)
	{
		node = (*stack);
		(*stack) = (*stack)->next;
		free(node);
	}
}

/**
 * @brief Free the two stack.
 * 
 * @param a Stack a.
 * @param b Stack b.
 */
void	free_stacks(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:33:39 by groka             #+#    #+#             */
/*   Updated: 2023/06/22 01:58:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules_bonus.h"

static int	swap(t_node **stack);

/**
 * @brief	sa (swap a): Swap the first 2 elements at the top of stack a.
 *			Do nothing if there is only one or no elements.
 * @param a Stack a.
 */
void	do_sa(t_node **a)
{
	swap(a);
}

/**
 * @brief	sb (swap b): Swap the first 2 elements at the top of stack b.
 *			Do nothing if there is only one or no elements.
 * @param b Stack a.
 */
void	do_sb(t_node **b)
{
	swap(b);
}

/**
 * @brief	ss : sa and sb at the same time
 * @param a Stack a.
 * @param b Stack b.
 */
void	do_ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}

/**
 * @brief	The function swaps the top 2 items on a stack.
 * 
 * @param stack 
 * @return int | 0 - if no need for swappind || 1 - if swapped |
 */
static int	swap(t_node **stack)
{
	if ((*stack == NULL) || ((*stack) == (*stack)->next))
		return (0);
	if ((*stack)->prev == (*stack)->next)
	{
		(*stack)->title = nohead;
		(*stack) = (*stack)->next;
		(*stack)->title = head;
	}
	else
	{
		(*stack)->title = nohead;
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->prev = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev->next = (*stack);
		(*stack)->next->prev = (*stack);
		(*stack) = (*stack)->prev;
		(*stack)->title = head;
	}
	return (1);
}

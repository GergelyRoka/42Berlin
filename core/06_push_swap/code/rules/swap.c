/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:33:39 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 12:33:40 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static int swap(t_node **stack);

/**
 * @brief	sa (swap a): Swap the first 2 elements at the top of stack a.
 *			Do nothing if there is only one or no elements.
 * @param a Stack a.
 */
void do_sa(t_node **a)
{
	if(swap(a))
		write(1, "sa\n", 3);
}

/**
 * @brief	sb (swap b): Swap the first 2 elements at the top of stack b.
 *			Do nothing if there is only one or no elements.
 * @param b Stack a.
 */
void do_sb(t_node **b)
{
	
	if(swap(b))
		write(1, "sb\n", 3);
}

/**
 * @brief	ss : sa and sb at the same time
 * @param a Stack a.
 * @param b Stack b.
 */
void do_ss(t_node **a, t_node **b)
{
	if(swap(a) + swap(b))
		write(1, "ss\n", 3);
}

/**
 * @brief	The function swaps the top 2 items on a stack.
 * 
 * @param stack 
 * @return int | 0 - if no need for swappind || 1 - if swapped |
 */
static int swap(t_node **stack)
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

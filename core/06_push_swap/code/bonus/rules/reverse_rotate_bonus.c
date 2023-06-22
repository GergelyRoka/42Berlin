/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:05:52 by groka             #+#    #+#             */
/*   Updated: 2023/06/22 01:58:44 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules_bonus.h"

static int	rrotate(t_node **stack);

/**
 * @brief	rra (reverse rotate a): Shift down all elements of stack a by 1.
 *			The last element becomes the first one.
 * 
 * @param a Stack a.
 */
void	do_rra(t_node **a)
{
	rrotate(a);
}

/**
 * @brief	rrb (reverse rotate b): Shift down all elements of stack b by 1.
 *			The last element becomes the first one.
 * 
 * @param b Stack b.
 */
void	do_rrb(t_node **b)
{
	rrotate(b);
}

/**
 * @brief	rrr : rra and rrb at the same time.
 * 
 * @param a	Stack a.
 * @param b	Stack b.
 */
void	do_rrr(t_node **a, t_node **b)
{
	rrotate(a);
	rrotate(b);
}

/**
 * @brief	Shift down all elements of a stack by 1.
 *			The last element becomes the first one.
 *
 * @param stack Stack.
 * @return int | (0) if no need to rotate, (1) when rotated.
 */
static int	rrotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = nohead;
	(*stack) = (*stack)->prev;
	(*stack)->title = head;
	return (1);
}

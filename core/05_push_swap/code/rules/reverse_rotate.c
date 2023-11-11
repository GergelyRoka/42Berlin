/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:05:52 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 15:44:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static int	rrotate(t_node **stack);

/**
 * @brief	rra (reverse rotate a): Shift down all elements of stack a by 1.
 *			The last element becomes the first one.
 * 
 * @param a Stack a.
 */
void	do_rra(t_node **a)
{
	if (rrotate(a))
		write(1, "rra\n", 4);
}

/**
 * @brief	rrb (reverse rotate b): Shift down all elements of stack b by 1.
 *			The last element becomes the first one.
 * 
 * @param b Stack b.
 */
void	do_rrb(t_node **b)
{
	if (rrotate(b))
		write(1, "rrb\n", 4);
}

/**
 * @brief	rrr : rra and rrb at the same time.
 * 
 * @param a	Stack a.
 * @param b	Stack b.
 */
void	do_rrr(t_node **a, t_node **b)
{
	if (rrotate(a) + rrotate(b))
		write(1, "rrr\n", 4);
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

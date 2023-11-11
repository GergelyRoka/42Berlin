/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:49:36 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 13:57:54 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static int	rotate(t_node **stack);

/**
 * @brief	ra (rotate a): Shift up all elements of stack a by 1.
 *			The first element becomes the last one
 * 
 * @param a	Stack a.
 */
void	do_ra(t_node **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

/**
 * @brief	rb (rotate b): Shift up all elements of stack b by 1.
 *			The first element becomes the last one.
 * 
 * @param b	Stack b.
 */
void	do_rb(t_node **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

/**
 * @brief	rr : ra and rb at the same time.
 * 
 * @param a	Stack a.
 * @param b	Stack b.
 */
void	do_rr(t_node **a, t_node **b)
{
	if (rotate(a) + rotate(b))
		write(1, "rr\n", 3);
}

/**
 * @brief	Shift up all elements of a stack by 1.
 *			The first element becomes the last one.
 * 
 * @param stack Stack.
 * @return int | 0 if no need for rotating. || 1 when rotate.
 */
static int	rotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = nohead;
	(*stack) = (*stack)->next;
	(*stack)->title = head;
	return (1);
}

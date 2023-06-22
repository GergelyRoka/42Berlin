/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:18 by groka             #+#    #+#             */
/*   Updated: 2023/06/22 03:26:56 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief	Return with true if the stack is sorted from top to bottom.
 * 			Ascending order.
 * 			Example: 1 2 3 4 5
 *
 * @param a Stack.
 * @return int false == 0, true == 1
 */
int	is_a_sorted(t_node *a)
{
	if (a == NULL)
		return (true);
	if (a == a->next)
		return (true);
	if (a->value > a->next->value)
		return (false);
	a = a->next;
	while (a->next->title != head)
	{
		if (a->value > a->next->value)
			return (false);
		a = a -> next;
	}
	return (true);
}

/**
 * @brief	Return with true if the stack is sorted from top to bottom.
 * 			Descending order.
 *			Example: 5 4 3 2 1
 *
 * @param a Stack.
 * @return int false == 0, true == 1
 */
int	is_b_sorted(t_node *b)
{
	if (b == NULL)
		return (true);
	if (b == b->next)
		return (true);
	if (b->value < b->next->value)
		return (false);
	b = b->next;
	while (b->next->title != head)
	{
		if (b->value < b->next->value)
			return (false);
		b = b -> next;
	}
	return (true);
}

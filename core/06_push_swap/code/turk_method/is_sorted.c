/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:18 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 02:02:02 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief	Return with true if every integer is sorted between the lowest and
 * 			the highest number.
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
	while (a->title != head)
	{
		if (a->value > a->next->value)
			return (false);
		a = a -> next;
	}
	return (true);
}

/**
 * @brief	Return with true if every integer is sorted between the highest and
 * 			the lowest number.
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
	while (b->title != head)
	{
		if (b->value < b->next->value)
			return (false);
		b = b -> next;
	}
	return (true);
}
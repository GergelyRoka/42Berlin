/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:56:28 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 02:13:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief	If every number is in ascending order between the minimum value and
 * 			the maximum value then returns true.
 * 			1) Example: 1 2 3 4 5
 * 			2) Example: 4 5 1 2 3
 * @param a Sack a.
 * @return int (1 - true) if the stack ordered || otherwise (0 - false)
 */
int	is_a_ordered(t_node *a)
{
	t_node	*min_node;
	t_node	*max_node;
	int		count;

	if (!a)
		return (true);
	min_node = min_node_in_stack(a);
	max_node = max_node_in_stack(a);
	count = 1;
	while (min_node != max_node)
	{
		if (min_node->value > min_node->next->value)
			return (false);
		min_node = min_node->next;
		++count;
	}
	if (count == size_of_stack(a))
		return (true);
	return (false);
}

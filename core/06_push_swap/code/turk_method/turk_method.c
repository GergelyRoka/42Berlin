/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:35 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 02:28:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief https://medium.com/@ayogun/push-swap-c1f5d2d41e97
 * 
 * @param a Stack A
 * @param b Stack B
 */
void	turk_method(t_node **a, t_node **b)
{
	if (is_a_sorted(*a) || is_a_ordered(*a))
	{
		finish_a(a);
		return ;
	}
	while (size_of_stack(*a) > 3 && !is_a_ordered(*a))
		push_from_a_to_b(a, b);
	if (size_of_stack(*a) == 3 && !is_a_ordered(*a))
		sort_three(a);
	empty_b(a, b);
	finish_a(a);
}

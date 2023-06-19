/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:35 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:17:19 by groka            ###   ########.fr       */
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
	while (size_of_stack(*a) > 5 && !is_a_ordered(*a))
		push_from_a_to_b(a, b);
	if (size_of_stack(*a) == 5 && !is_a_ordered(*a))
		ft_five_nums(a, b);
	empty_b(a, b);
	finish_a(a);
}

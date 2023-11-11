/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:41:17 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 03:57:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief Sort a stack when it contains 3 integers.
 * 
 * @param stack A stack.
 */
void	sort_three(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->prev->value;
	if (middle < bottom && middle < top && bottom > top)
		do_sa(stack);
	else if (top > middle && top > bottom && middle > bottom)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (top > middle && top > bottom && middle < bottom)
		do_ra(stack);
	else if (top < middle && top < bottom && middle > bottom)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (top < middle && top > bottom && middle > bottom)
		do_rra(stack);
}

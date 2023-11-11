/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:32 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:17:00 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief Calculate the size of a stack.
 * 
 * @param stack		A stack.
 * @return int		Size of a stack.
 */
int	size_of_stack(t_node *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (1);
	stack = stack->next;
	size = 1;
	while (stack->title != head)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

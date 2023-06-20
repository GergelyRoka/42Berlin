/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:05:31 by saimar            #+#    #+#             */
/*   Updated: 2023/06/20 03:09:37 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk_method/turk_method.h"
#include "linked_list/linked_list.h"
#include "./libft/libft.h"
#include "argument_validation/argument_validation.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac == 1)
		return (0);
	if (!argument_validation(av))
	{
		write(2, "Error\n", 6);
		return (42);
	}
	a = create_stack(av);
	b = NULL;
	turk_method(&a, &b);
	free_stacks(&a, &b);
	return (0);
}

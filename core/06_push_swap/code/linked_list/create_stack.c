/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:46:27 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 09:30:01 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	malloc_error_exit(t_node **head);

/**
 * @brief Create a stack using command line arguments.
 * 
 * @param av Command line arguments.
 * @return t_node* Top/head of the stack.
 */
t_node	*create_stack(char **av)
{
	int		i;
	t_node	*stack_head;

	stack_head = create_node(ft_atoi(av[1]));
	if (!(stack_head))
		malloc_error_exit(&stack_head);
	stack_head->title = head;
	stack_head->next = stack_head;
	stack_head->prev = stack_head;
	i = 2;
	while (av[i])
	{
		stack_head->prev->next = create_node(ft_atoi(av[i]));
		if (!(stack_head->prev->next))
			malloc_error_exit(&stack_head);
		stack_head->prev->next->next = stack_head;
		stack_head->prev->next->prev = stack_head->prev;
		stack_head->prev = stack_head->prev->next;
		stack_head->prev->title = nohead;
		i++;
	}
	return (stack_head);
}

/**
 * @brief	Function for Malloc failure.
 * 			If malloc failed, free the list, and exit.
 * 
 * @param head Head of the stack/list;
 */
static void	malloc_error_exit(t_node **head)
{
	free_stack(head);
	write(2, "Error\n", 6);
	write(2, "Malloc failure.\n", 16);
	exit(42);
}

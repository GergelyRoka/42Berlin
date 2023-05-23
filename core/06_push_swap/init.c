/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:42 by groka             #+#    #+#             */
/*   Updated: 2023/05/23 09:37:17 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int, because if malloc crash, should end the program

/**
 * @brief Initializing the stacks (linked lists). Filling stack 'a' from input. 
 * 
 *  @param **a Head of stack 'a'. It is the top of 'a'.
 *  @param **b Head of stack 'b'. It is the top of 'b'.
 *  @param size The amount of numbers for the stack 'a' from argv
 *  @param **argv The list of commandline arguments, expected integers.
 * 
 *  @return: (-1) if malloc didn't work -> error ; otherwise (0)
 */
int init(t_node **a, t_node **b, int size, char **argv)
{
	t_node	*current_node;

	*b = NULL;
	*a = create_node(atoi(*argv));
	argv++;
	if (*a == NULL)
		return (-1);
	current_node = *a;
	size--;
	while(size--)
	{
		current_node->next = create_node(atoi(*argv));
		++argv;
		current_node = current_node->next;
		if (current_node == NULL)
			return (-1);
	}
	return (0);
}


//TODO
//good val should be param
//malloc check and error handling
/**
 * @brief Create a node object
 * 
 * @param val 
 * @return t_node* 
 */
t_node	*create_node(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = val;
	node->next = NULL;

	return (node);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:39:11 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:31:14 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

/**
 * @brief Create a node object
 * 
 * @param n The value, the integer of the node.
 * @return t_node* 
 */
t_node	*create_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

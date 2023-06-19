/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:46:27 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 17:01:20 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node  *create_stack(char **av) // add at the end -- when you call this you need to know there is at least one av
{
	int		i;
	t_node	*new_node;
	t_node	*header;
	t_node	*curr;

	new_node = create_node(ft_atoi(av[1]));
	curr = new_node;
	curr->title = head;
	new_node->next = new_node;
	new_node->prev = new_node;
	header = curr;
	i = 2;
	while(av[i])
	{
		new_node = create_node(ft_atoi(av[i]));
		header->prev = new_node;
		new_node->next = header;
		curr->next = new_node;
		new_node->prev = curr;
		curr = new_node;
		curr->title = nohead;
		i++;
	}
	return(header);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:42 by groka             #+#    #+#             */
/*   Updated: 2023/06/10 08:17:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *create_node(int value);

void init(t_stack *a, t_stack *b, char **array, int n)
{
	t_node *new;

	a->head = NULL;
	a->last = NULL;
	b->head = NULL;
	b->last = NULL;

	int i = 1;
	while(i < n)
	{
		new = create_node(atoi(array[i]));
		if (a->head == NULL)
		{
			a->head = new;
			a->last = new;
		}
		a->last->next = new;
		new->prev = a->last;
		a->last = new;
		a->last->next = a->head;
		a->head->prev = a->last;
		i++;
	}
}

t_node *create_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->value = value;

	return (node);
}

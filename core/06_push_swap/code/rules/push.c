/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:33:10 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 14:03:37 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static int		push(t_node **dest, t_node **src);
static t_node	*pop(t_node **src);

/**
 * @brief	pa (push a): Take the first element at the top of b and put it at
 *			the top of a.
 *			Do nothing if b is empty
 * @param a Stack a.
 * @param b Stabk b.
 */
void	do_pa(t_node **a, t_node **b)
{
	if (push(a, b))
		write(1, "pa\n", 3);
}

/**
 * @brief	pb (push b): Take the first element at the top of a and
 *			put it at the top of b.
 *			Do nothing if a is empty.
 * @param a Stack a.
 * @param b Stack b.
 */
void	do_pb(t_node **a, t_node **b)
{
	if (push(b, a))
		write(1, "pb\n", 3);
}

/**
 * @brief Push the top item from stack source to stack destination.
 * 
 * @param dest Stack, the destination.
 * @param src Stack, the source.
 * @return int 
 */
static int	push(t_node **dest, t_node **src)
{
	t_node *new_head;

	if(*src == NULL)
		return(0);
	if(!(*dest))
	{
		*dest = pop(src);
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
	}
	else
	{
		new_head = pop(src);
		(*dest)->prev->next = new_head;
		new_head->prev = (*dest)->prev; 
		new_head->next = (*dest);
		(*dest)->prev = new_head;
		(*dest)->title = nohead;
		(*dest) = new_head;
	}
	return (1);
}

/**
 * @brief	Pop up the top item from the source stack.
 * 
 * @param src Stack, the source.
 * @return t_node* The formal top item of the stack src.
 */
static t_node	*pop(t_node **src)
{
	t_node *top;

	if(*src == (*src)->next)
	{
		top = *src;
		*src = NULL;
		return (top);
	}
	else
	{	
		top = *src;
		(*src)->prev->next = (*src)->next; 
		(*src)->next->prev = (*src)->prev;
		(*src) = (*src)->next;
		(*src)->title = head;
	}
	return(top);
}

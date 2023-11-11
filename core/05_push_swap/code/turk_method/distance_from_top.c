/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_from_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:13 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:09:28 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

/**
 * @brief		Calculate the distance of a node from top using rotate.
 * 				How many do_ra/do_rb needed to reach top position for a node.
 * @note		The node should be an item of the stack.
 * @param node 	A node to the top!
 * @return int 	Steps to the top.
 */
int	dist_w_rot(t_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->title == head)
		return (dist);
	while (node->title != head)
	{
		++dist;
		node = node->prev;
	}
	return (dist);
}

/**
 * @brief		Calculate the distance of a node from top using rotate.
 * 				How many do_ra/do_rb needed to reach top position for a node.
 * @note		The node should be an item of the stack.
 * @param node	A node to the top!
 * @return int	Steps to the top.
 */
int	dist_w_rev_rot(t_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->title == head)
		return (dist);
	while (node->title != head)
	{
		++dist;
		node = node->next;
	}
	return (dist);
}

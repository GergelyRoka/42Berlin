/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_moves_n_steps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:36:56 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:11:00 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static int	max(int x, int y);
static void	fill_moves(t_node *b, t_node *node);
static void	fill_steps(t_node *node);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 */
void	fill_moves_n_steps(t_node *a, t_node *b)
{
	if (a == NULL)
		return ;
	fill_moves(b, a);
	fill_steps(a);
	a = a->next;
	while (a->title != head)
	{
		fill_moves(b, a);
		fill_steps(a);
		a = a->next;
	}
}

/**
 * @brief	Fill the member "moves" of a node.
 * 			Calculating the rotates and steps.
 * 
 * @param b		Stack B.
 * @param node	Target node;
 */
static void	fill_moves(t_node *b, t_node *node)
{
	node->moves[0].rot_a = dist_w_rot(node);
	node->moves[0].rot_b = dist_w_rot(node_new_pos_b(b, node));
	node->moves[0].steps = max(node->moves[0].rot_a, node->moves[0].rot_b);
	node->moves[1].rot_a = dist_w_rot(node);
	node->moves[1].rot_b = -dist_w_rev_rot(node_new_pos_b(b, node));
	node->moves[1].steps = node->moves[1].rot_a - node->moves[1].rot_b;
	node->moves[2].rot_a = -dist_w_rev_rot(node);
	node->moves[2].rot_b = dist_w_rot(node_new_pos_b(b, node));
	node->moves[2].steps = -node->moves[2].rot_a + node->moves[2].rot_b;
	node->moves[3].rot_a = -dist_w_rev_rot(node);
	node->moves[3].rot_b = -dist_w_rev_rot(node_new_pos_b(b, node));
	node->moves[3].steps = max(-node->moves[3].rot_a, -node->moves[3].rot_b);
}

/**
 * @brief	Calculating the cheapest/fewest steps
 * 			and fill the member "steps" of a node with it.
 * 
 * @param node 
 */
static void	fill_steps(t_node *node)
{
	int	i;
	int	steps;

	steps = node->moves[0].steps;
	i = 1;
	while (i < 4)
	{
		if (node->moves[i].steps < steps)
			steps = node->moves[i].steps;
		++i;
	}
	node->steps = steps;
}

/**
 * @brief Gives back the highest number of two.
 * 
 * @param x 
 * @param y 
 * @return int 
 */
static int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

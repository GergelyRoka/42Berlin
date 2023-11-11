/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_form_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:28 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 08:36:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static t_node	*cheapest_node(t_node *stack);
static void		do_rotates_part_one(t_node **a, t_node **b, t_moves *moves);
static void		do_rotates_part_two(t_node **a, t_node **b, t_moves *moves);
static t_moves	*cheapest_move(t_node *node);

/**
 * @brief 
 * 
 * @param a Stack a.
 * @param b Stack b.
 */
void	push_from_a_to_b(t_node **a, t_node **b)
{
	t_node	*moving_node;
	t_moves	*move;

	fill_moves_n_steps(*a, *b);
	moving_node = cheapest_node(*a);
	move = cheapest_move(moving_node);
	do_rotates_part_one(a, b, move);
	do_rotates_part_two(a, b, move);
	if (*a != moving_node)
		write(1, "ERROR with push_from_a_to_b\n", 28);
	do_pb(a, b);
}

/**
 * @brief Pick the first node from a stack with the lowest "steps".
 * 
 * @param stack 
 * @return t_node* 
 */
static t_node	*cheapest_node(t_node *stack)
{
	t_node	*cheapest_node;

	if (stack == NULL)
		return (NULL);
	cheapest_node = stack;
	if (stack == stack->next)
		return (cheapest_node);
	stack = stack->next;
	while (stack->title != head)
	{
		if (cheapest_node->steps > stack->steps)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

/**
 * @brief Using a node's moves to rotate the stacks. Part 1.
 * 
 * @param a Stack a.
 * @param b Stack b.
 * @param moves The moving node's moves.
 */
static void	do_rotates_part_one(t_node **a, t_node **b, t_moves *moves)
{
	while (moves->rot_a > 0 && moves->rot_b > 0)
	{
		moves->rot_a--;
		moves->rot_b--;
		do_rr(a, b);
	}
	while (moves->rot_a > 0)
	{
		moves->rot_a--;
		do_ra(a);
	}
	while (moves->rot_b > 0)
	{
		moves->rot_b--;
		do_rb(b);
	}
}

/**
 * @brief Using a node's moves to rotate the stacks. Part 2.
 * 
 * @param a Stack a.
 * @param b Stack b.
 * @param moves The moving node's moves.
 */
static void	do_rotates_part_two(t_node **a, t_node **b, t_moves *moves)
{
	while (moves->rot_a < 0 && moves->rot_b < 0)
	{
		moves->rot_a++;
		moves->rot_b++;
		do_rrr(a, b);
	}
	while (moves->rot_a < 0)
	{
		moves->rot_a++;
		do_rra(a);
	}
	while (moves->rot_b < 0)
	{
		moves->rot_b++;
		do_rrb(b);
	}
}

/**
 * @brief The function gives back the first cheapest move of a node.
 * 
 * @param node A node.
 * @return t_moves* Member moves of struct node.
 */
static t_moves	*cheapest_move(t_node *node)
{
	t_moves	*move;
	int		i;

	move = &(node->moves[0]);
	i = 1;
	while (i < 4)
	{
		if (move->steps > node->moves[i].steps)
			move = &(node->moves[i]);
		++i;
	}
	return (move);
}

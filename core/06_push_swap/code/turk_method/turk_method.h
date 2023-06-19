/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:38 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 14:07:16 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_METHOD_H
# define TURK_METHOD_H

#include "../push_swap.h"

enum boolean {false, true};

//turk_method.c
void	turk_method(t_node **a, t_node **b);

void	push_from_a_to_b(t_node **a, t_node **b);

int		size_of_stack(t_node *stack);

int		is_a_ordered(t_node *a);
int		is_b_ordered(t_node *b);

int dist_w_rot(t_node *node);
int dist_w_rev_rot(t_node *node);

void	fill_moves_n_steps(t_node *a, t_node *b);

t_node	*node_new_pos_b(t_node *b, t_node *node);
t_node	*max_node_in_stack(t_node *stack);
t_node	*min_node_in_stack(t_node *stack);

t_node *node_new_pos_a(t_node *a, t_node *node);

#endif
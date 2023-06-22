/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:55:23 by groka             #+#    #+#             */
/*   Updated: 2023/06/22 01:58:28 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "../../push_swap_types.h"

//swap.c
void	do_sa(t_node **a);
void	do_sb(t_node **b);
void	do_ss(t_node **a, t_node **b);
//push.c
void	do_pa(t_node **a, t_node **b);
void	do_pb(t_node **a, t_node **b);
//rotate.c
void	do_ra(t_node **a);
void	do_rb(t_node **b);
void	do_rr(t_node **a, t_node **b);
//reverse_rotate.c
void	do_rra(t_node **a);
void	do_rrb(t_node **b);
void	do_rrr(t_node **a, t_node **b);

#endif
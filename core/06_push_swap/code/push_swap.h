/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:33:29 by groka             #+#    #+#             */
/*   Updated: 2023/06/19 17:27:16 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
//#include "turk_method/turk_method.h"
#include "push_swap_types.h"
#include "rules/rules.h"


//CHECKERS
int	check_duplicates(char **av);
int	check_digit(char *str);

//OTHERS
t_node	*create_stack(char **av);
t_node	*create_node(int n);
void	print_stack(t_node *a);
/*
//RULES
void		do_sa(t_node **a);
void		do_sb(t_node **b);
void		do_ss(t_node **a, t_node **b);
void		do_pa(t_node **a, t_node **b);
void		do_pb(t_node **a, t_node **b);
int		push(t_node **a, t_node **b);
int		rotate(t_node **stack);
void		do_rr(t_node **a, t_node **b);
void		do_rb(t_node **b);
void		do_ra(t_node **a);
int		rrotate(t_node **stack);
void		do_rrb(t_node **b);
void		do_rra(t_node **a);
void		do_rrr(t_node **a, t_node **b);
t_node		*pull(t_node **src);
*/
void	ft_three_nums(t_node **stack);
void	ft_five_nums(t_node **a, t_node **b);

void	ft_sort_big(t_node **a, t_node **b, int *array, int size);

void _10minutes_sort(t_node **a, t_node **b);

//array
void	bubble_sort(int *array, int size);
int		*create_array(int size, t_node *stack);
void	array_three_biggest_number(int size, int *array, t_node *stack);

#endif

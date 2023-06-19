/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:33:29 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:55:04 by groka            ###   ########.fr       */
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

void	ft_three_nums(t_node **stack);
void	ft_five_nums(t_node **a, t_node **b);

void _10minutes_sort(t_node **a, t_node **b);

#endif

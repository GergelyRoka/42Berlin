/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:50 by groka             #+#    #+#             */
/*   Updated: 2023/06/10 04:13:58 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

/**
 * @brief Element type for the stacks.
 * 
 */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
}			t_stack;

//dev helpers
void	dev_write_stack(t_stack	stack);

//RULES
//swap
void do_sa(t_stack *a);
void do_sb(t_stack *b);
void do_ss(t_stack *a, t_stack *b);


//init
void init(t_stack *a, t_stack *b, char **array, int n);
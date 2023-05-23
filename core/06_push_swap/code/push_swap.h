/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:50 by groka             #+#    #+#             */
/*   Updated: 2023/05/23 09:28:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Element type for the stacks.
 * 
 */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

//init.c
int init(t_node **a, t_node **b, int size, char **argv);

t_node	*create_node(int val);



//dev helpers
void	dev_write_list(t_node	*list);
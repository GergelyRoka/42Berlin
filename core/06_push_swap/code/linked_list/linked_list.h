/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:37:56 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:30:09 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include "../push_swap_types.h"
# include "../libft/libft.h"

t_node	*create_node(int n);
t_node	*create_stack(char **av);
void	free_stack(t_node **stack);

#endif
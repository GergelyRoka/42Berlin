/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:38:52 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 04:08:30 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPES_H
# define PUSH_SWAP_TYPES_H

# include <unistd.h>

typedef enum e_title {nohead, head}	t_title;

enum e_boolean {false, true};

/**
 * @brief A way to the top!
 * 
 * @member rot_a	|| How many times to rotate stack a. + ra - rra
 * @member rot_b	|| How many times to rotate stack b. + rb - rrb
 * @member steps	|| The number of steps, rotates to the top!
 */

typedef struct s_moves
{
	int	rot_a;
	int	rot_b;
	int	steps;
}	t_moves;

/**
 * @brief	A node struct for a circular doubly linked list.
 * 
 * @member int value 			|| The integer.
 * @member struct s_node *prev	|| The previus node.
 * @member struct s_node *next	|| The next node.
 * @member t_title title		|| The title. (nohead, head)
 * @member int steps			|| The shortest way/rotates to the top.
 * @member t_moves moves[4]		|| The moves. 4 ways to the top.
 */
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	t_title			title;
	int				steps;
	t_moves			moves[4];
}	t_node;

#endif
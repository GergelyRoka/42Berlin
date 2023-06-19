/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:38:52 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 00:46:13 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPES_H
# define PUSH_SWAP_TYPES_H

# include <unistd.h>

typedef enum	e_title {nohead, head} t_title;

typedef struct	s_moves
{
	int rot_a;
	int	rot_b;
	int	steps;
}	t_moves;

/**
 * @brief 
 * @member value Integer number.
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
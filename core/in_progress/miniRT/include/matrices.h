/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:15:08 by groka             #+#    #+#             */
/*   Updated: 2024/04/02 21:48:51 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdbool.h>
# include "tuples.h"

typedef struct s_matrix
{
	int		size;
	double	matrix[4][4];
}	t_matrix;

bool		is_equal_matrix(t_matrix a, t_matrix b);
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_tuple(t_matrix a, t_tuple b);
t_matrix	identity_matrix(void);
t_matrix	transpose_matrix(t_matrix a);
void		print_matrix(t_matrix a);
double		minor_matrix(t_matrix a, int x, int y);

#endif

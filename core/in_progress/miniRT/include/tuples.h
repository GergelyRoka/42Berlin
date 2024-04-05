/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:32:16 by groka             #+#    #+#             */
/*   Updated: 2024/04/02 18:21:58 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

#include <math.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuple;

typedef t_tuple	t_point;
typedef t_tuple	t_vector;

// tuples_a.c

t_tuple		do_point(double x, double y, double z);
t_tuple		do_vector(double x, double y, double z);

// tuples_b.c

t_tuple		add_tuple_tuple(t_tuple a, t_tuple b);
t_vector	subtract_point_point(t_point a, t_point b);
t_point		subtract_point_vector(t_point a, t_vector b);
t_vector	subtract_vector_vector(t_vector a, t_vector b);
t_tuple		negating_tuple(t_tuple a);

// tuples_c.c

t_tuple		multiply_tuple_double(t_tuple a, double b);
double		magnitude(t_tuple a);
t_tuple		normalize(t_tuple a);
double		dot_product(t_tuple a, t_tuple b);
t_vector	cross_product(t_vector v1, t_vector v2);

#endif

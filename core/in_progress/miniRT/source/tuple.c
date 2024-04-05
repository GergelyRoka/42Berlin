/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:00:18 by groka             #+#    #+#             */
/*   Updated: 2024/03/25 13:45:39 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tuple.h"
#include <stdio.h>

t_tuple	make_tuple(double x, double y, double z, double w)
{
	return ((t_tuple){x, y, z, w});
}

/*
	Chapter 1. Tuples, Points, and Vectors • 4
*/
t_tuple	make_point(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 1.});
}

/*
	Chapter 1. Tuples, Points, and Vectors • 4
*/
t_tuple	make_vector(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 0.});
}

t_tuple	adding_tuples(t_tuple a, t_tuple b)
{
	return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_vect	subtracting_point_point(t_point p1, t_point p2)
{
	return ((t_vect){p1.x - p2.x, p1.y - p2.y, p1.z - p2.z, p1.w - p2.w});
}

t_point	subtracting_point_vector(t_point p, t_vect v)
{
	return ((t_point){p.x - v.x, p.y - v.y, p.z - v.z, p.w - v.w});
}

t_vect	subtracting_vector_vector(t_vect v1, t_vect v2)
{
	return ((t_vect){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w});
}

t_tuple	negating_tuple(t_tuple t)
{
	return ((t_tuple){-t.x, -t.y, -t.z, -t.w});
}

t_tuple	multiplying_tuple_scalar(t_tuple t, double s)
{
	return ((t_tuple){t.x * s, t.y * s, t.z * s, t.w * s});
}

t_tuple	dividing_tuple_scalar(t_tuple t, double s)
{
	return ((t_tuple){t.x / s, t.y / s, t.z / s, t.w / s});
}

double	magnitude(t_tuple t)
{
	return (sqrt(t.x * t.x + t.y * t.y + t.z * t.z + t.w * t.w));
}

t_vect	normalize(t_tuple t)
{
	return ((t_vect){
		t.x / magnitude(t),\
		t.y / magnitude(t),\
		t.z / magnitude(t),\
		t.w / magnitude(t)});
}

double	dot_product(t_tuple t1, t_tuple t2)
{
	return (t1.x * t2.x + t1.y * t2.y + t1.z * t2.z + t1.w * t2.w);
}



int	main(void)
{
	t_tuple	p, b;

	p = make_point(1,2,3);
	b = make_point(1,2,3);
	p = adding_tuples(p, b);
	printf("%f %f %f %f\n", p.x, p.y, p.z, p.w);

	t_vect v = make_vector(1,2,3);

	v = negating_tuple(v);

	printf("%f %f %f %f\n", v.x, v.y, v.z, v.w);

	printf("%d\n", v.w == negating_tuple(v).w);
	printf("%d\n", v.w == 9);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:58:20 by groka             #+#    #+#             */
/*   Updated: 2024/03/26 16:24:45 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/tuples.h"
// Scalar Multiplication
// Scenario: Multiplying a tuple by a scalar
// Given a ← tuple(1, -2, 3, -4)
// Then a * 3.5 = tuple(3.5, -7, 10.5, -14)
// Scenario: Multiplying a tuple by a fraction
// Given a ← tuple(1, -2, 3, -4)
// Then a * 0.5 = tuple(0.5, -1, 1.5, -2)
t_tuple	multiply_tuple_double(t_tuple a, double b)
{
	return ((t_tuple){a.x * b, a.y * b, a.z * b, a.w * b});
}

// Magnitude
double	magnitude(t_tuple a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
}

// Normalize
// function normalize(v)
// return tuple(v.x / magnitude(v),
// v.y / magnitude(v),
// v.z / magnitude(v),
// v.w / magnitude(v))
// end function
// With  that,  you  can  turn  any  vector
// (or  rather,  any  vector  with  a  nonzero magnitude)
// into a unit vector.
t_tuple	normalize(t_tuple a)
{
	return (multiply_tuple_double(a, 1.0 / magnitude(a)));
}

// Dot Product
// When dealing with vectors, a dot product (also called a scalar product,
// or inner product) is going to turn up when you start intersecting rays
// with objects, as well as when you compute the shading on a surface.
// The dot product takes two vectors and returns a scalar value.
// Add this test to demonstrate the dot product’s effect.
// features/tuples.feature
// Scenario: The dot product of two tuples
// Given a ← vector(1, 2, 3)
// And b ← vector(2, 3, 4)
// Then dot(a, b) = 20
double	dot_product(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

// Cross Product
// Cross product of two vectors is a vector that is perpendicular to both
t_vector	cross_product(t_vector v1, t_vector v2)
{
	return ((t_vector){
		(v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.x * v2.y) - (v1.y * v2.x),
		0.0});
}

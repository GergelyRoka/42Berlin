/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:41:06 by groka             #+#    #+#             */
/*   Updated: 2024/03/26 16:09:40 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/tuples.h"

// Scenario: Adding two tuples
// Given a1 ← tuple(3, -2, 5, 1)
// And a2 ← tuple(-2, 3, 1, 0)
// Then a1 + a2 = tuple(1, 1, 6, 1)
t_tuple	add_tuple_tuple(t_tuple a, t_tuple b)
{
	return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

// Scenario: Subtracting two points
// Given p1 ← point(3, 2, 1)
// And p2 ← point(5, 6, 7)
// Then p1 - p2 = vector(-2, -4, -6)
t_vector	subtract_point_point(t_point p1, t_point p2)
{
	return ((t_vector){p1.x - p2.x, p1.y - p2.y, p1.z - p2.z, 0.0});
}

// Similarly, you can subtract a vector (w  of  0) from a point (w of 1)
// and get
// another tuple with a w of 1—a point. Conceptually, this is just moving back-
// ward by the given vector. Add this next test to demonstrate this.
// features/tuples.feature
// Scenario: Subtracting a vector from a point
// Given p ← point(3, 2, 1)
// And v ← vector(5, 6, 7)
// Then p - v = point(-2, -4, -6)
t_point	subtract_point_vector(t_point p, t_vector v)
{
	return ((t_point){p.x - v.x, p.y - v.y, p.z - v.z, 1.0});
}

//Lastly, subtracting two vectors gives us a tuple with a w of 0—another vector,
// representing the change in direction between the two. Write another test to
// show that this works.
// Chapter 1. Tuples, Points, and Vectors • 6
// report erratum  •  discuss
// features/tuples.feature
// Scenario: Subtracting two vectors
// Given v1 ← vector(3, 2, 1)
// And v2 ← vector(5, 6, 7)
// Then v1 - v2 = vector(-2, -4, -6)
// As with addition, though, not every combination makes sense. For instance,
// if you subtract a point (w=1) from a vector (w=0),
// you’ll end up with a negative
// w component, which is neither point nor vector. Let’s look at a counterpart
// to subtraction next.
t_vector	subtract_vector_vector(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, 0.0});
}

// Negating Tuples
// Sometimes you’ll want to know what the opposite of some vector is. That is
// to say, given a vector that points from a surface toward a light source, what
// vector points from the light source back to the surface?
// (You’ll run into this
// specific case in Chapter 6, Light and Shading, on page 75, as well.)
// Mathematically, you can get it by subtracting the vector
// from the tuple (0, 0, 0, 0). Go
// ahead and write a test like the following, to demonstrate this
t_tuple	negating_tuple(t_tuple a)
{
	return ((t_tuple){-a.x, -a.y, -a.z, -a.w});
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:47:42 by groka             #+#    #+#             */
/*   Updated: 2024/04/01 16:51:24 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}			t_color;

/*
Scenario: Colors are (red, green, blue) tuples
Given c ← color(-0.5, 0.4, 1.7)
Then c.red = -0.5
And c.green = 0.4
And c.blue = 1.7

Scenario: Adding colors
Given c1 ← color(0.9, 0.6, 0.75)
And c2 ← color(0.7, 0.1, 0.25)
Then c1 + c2 = color(1.6, 0.7, 1.0)
Scenario: Subtracting colors
Given c1 ← color(0.9, 0.6, 0.75)
And c2 ← color(0.7, 0.1, 0.25)
Then c1 - c2 = color(0.2, 0.5, 0.5)
Scenario: Multiplying a color by a scalar
Given c ← color(0.2, 0.3, 0.4)
Then c * 2 = color(0.4, 0.6, 0.8)

Scenario: Multiplying colors
Given c1 ← color(1, 0.2, 0.4)
And c2 ← color(0.9, 1, 0.1)
Then c1 * c2 = color(0.9, 0.2, 0.04)

function hadamard_product(c1, c2)
r ← c1.red * c2.red
g ← c1.green * c2.green
b ← c1.blue * c2.blue
return color(r, g, b)
end function

*/

t_color	color(double red, double green, double blue);
t_color	color_add(t_color c1, t_color c2);
t_color	color_sub(t_color c1, t_color c2);
t_color	color_mul_scalar(t_color c, double scalar);
t_color	color_mul(t_color c1, t_color c2);
t_color	color_hadamard_product(t_color c1, t_color c2);


#endif
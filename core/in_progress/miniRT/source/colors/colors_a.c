/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:51:51 by groka             #+#    #+#             */
/*   Updated: 2024/04/01 16:53:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/colors.h"

t_color	color(double red, double green, double blue)
{
	return ((t_color){red, green, blue});
}

t_color	color_add(t_color c1, t_color c2)
{
	return ((t_color){c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue});
}

t_color	color_sub(t_color c1, t_color c2)
{
	return ((t_color){c1.red - c2.red, c1.green - c2.green, c1.blue - c2.blue});
}

t_color	color_mul_scalar(t_color c, double scalar)
{
	return ((t_color){c.red * scalar, c.green * scalar, c.blue * scalar});
}

t_color	color_mul(t_color c1, t_color c2)
{
	return ((t_color){c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue});
}

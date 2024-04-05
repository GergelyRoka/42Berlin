/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:52:51 by groka             #+#    #+#             */
/*   Updated: 2024/04/01 16:53:17 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/colors.h"

t_color	color_hadamard_product(t_color c1, t_color c2)
{
	return ((t_color){c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue});
}

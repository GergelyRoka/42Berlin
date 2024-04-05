/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:12:17 by groka             #+#    #+#             */
/*   Updated: 2024/04/01 20:22:55 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "colors.h"

t_color	**create_canvas(int width, int height);
void	write_pixel(t_color **canvas, int x, int y, t_color color);
void	free_canvas(t_color **canvas);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_wall_visibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:37:30 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:37:47 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	show_insta_img_wall(int index, int i, int j)
{
	class_img_wall(NULL)->instances[index].enabled = true;
	class_img_wall(NULL)->instances[index].x = j * WIDTH;
	class_img_wall(NULL)->instances[index].y = i * HEIGHT;
	class_img_wall(NULL)->instances[index].z = Z_IMG_WALL;
}

void	hide_insta_img_wall(int index)
{
	class_img_wall(NULL)->instances[index].enabled = false;
}

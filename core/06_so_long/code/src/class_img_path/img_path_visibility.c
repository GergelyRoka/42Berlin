/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_path_visibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:49:56 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 03:55:14 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	show_insta_img_path(int index, int i, int j)
{
	class_img_path(NULL)->instances[index].enabled = true;
	class_img_path(NULL)->instances[index].x = j * WIDTH + 10;
	class_img_path(NULL)->instances[index].y = i * HEIGHT + 10;
	class_img_path(NULL)->instances[index].z = Z_IMG_PATH;
}

void	hide_insta_img_path(int index)
{
	class_img_path(NULL)->instances[index].enabled = false;
}

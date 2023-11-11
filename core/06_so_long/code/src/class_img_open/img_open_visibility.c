/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_open_visibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:54:12 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:55:13 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	show_insta_img_open(int index, int i, int j)
{
	class_img_open(NULL)->instances[index].enabled = true;
	class_img_open(NULL)->instances[index].x = j * WIDTH;
	class_img_open(NULL)->instances[index].y = i * HEIGHT;
	class_img_open(NULL)->instances[index].z = Z_IMG_OPEN;
}

void	hide_insta_img_open(int index)
{
	class_img_open(NULL)->instances[index].enabled = false;
}

void	insta_open_hide(int index)
{
	(class_img_open(NULL)->instances)[index].enabled = false;
}

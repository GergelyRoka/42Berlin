/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_exit_visibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:56:05 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 04:40:18 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	show_insta_img_exit(int index, int i, int j)
{
	class_img_exit(NULL)->instances[index].enabled = true;
	class_img_exit(NULL)->instances[index].x = j * WIDTH - 100;
	class_img_exit(NULL)->instances[index].y = i * HEIGHT - 310;
	class_img_exit(NULL)->instances[index].z = Z_IMG_EXIT;
}

void	hide_insta_img_exit(int index)
{
	class_img_exit(NULL)->instances[index].enabled = false;
}

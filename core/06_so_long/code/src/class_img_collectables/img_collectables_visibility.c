/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_collectables_visibility.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:56:59 by groka             #+#    #+#             */
/*   Updated: 2023/08/03 12:05:28 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	show_insta_img_coll(int index, int i, int j)
{
	static int	s;

	if (index == 0 || s > Z_IMG_PLAYER)
		s = 0;
	class_img_coll(NULL)->instances[index].enabled = true;
	class_img_coll(NULL)->instances[index].x = j * WIDTH - 30;
	class_img_coll(NULL)->instances[index].y = i * HEIGHT - 30;
	class_img_coll(NULL)->instances[index].z = Z_IMG_COLL + s;
	++s;
}

void	hide_insta_img_coll(int index)
{
	class_img_coll(NULL)->instances[index].enabled = false;
}

void	insta_coll_hide(int index)
{
	(class_img_coll(NULL)->instances)[index].enabled = false;
}

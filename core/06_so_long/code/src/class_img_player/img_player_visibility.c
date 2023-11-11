/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_player_visibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:03:42 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 04:35:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	show_insta_img_player(int index, int i, int j)
{
	class_img_player(NULL)->instances[index].enabled = true;
	class_img_player(NULL)->instances[index].x = j * WIDTH - 50;
	class_img_player(NULL)->instances[index].y = i * HEIGHT - 60;
	class_img_player(NULL)->instances[index].z = Z_IMG_PLAYER;
}

void	hide_insta_img_player(int index)
{
	class_img_player(NULL)->instances[index].enabled = false;
}

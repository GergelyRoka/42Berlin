/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_img_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:44:11 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 20:04:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* private */
mlx_image_t	*class_img_player(mlx_texture_t *texture)
{
	static mlx_image_t		*img;

	if (texture != NULL)
	{
		img = mlx_texture_to_image(get_mlx(), texture);
		mlx_delete_texture(texture);
	}
	return (img);
}
/* public */

void	set_texture_player(char *file)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file);
	if (texture == NULL)
		error_closemlx_exit(ERRMSG_TEXTURE_PLAYER);
	class_img_player(texture);
}

mlx_image_t	*get_img_player(void)
{
	return (class_img_player(NULL));
}

int	new_instance_player(int x, int y)
{
	int	index;

	index = mlx_image_to_window(get_mlx(), get_img_player(), x, y);
	if (index < 0)
		error_closemlx_exit(ERRMSG_INSTANCE);
	mlx_set_instance_depth(&get_img_player()->instances[index], Z_IMG_PLAYER);
	return (index);
}

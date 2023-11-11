/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_img_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:54:17 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:55:47 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* private */
mlx_image_t	*class_img_open(mlx_texture_t *texture)
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

void	set_texture_open(char *file)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file);
	if (texture == NULL)
		error_closemlx_exit(ERRMSG_TEXTURE_OPEN);
	class_img_open(texture);
}

mlx_image_t	*get_img_open(void)
{
	return (class_img_open(NULL));
}

int	new_instance_open(int x, int y)
{
	int	index;

	index = mlx_image_to_window(get_mlx(), get_img_open(), x, y);
	if (index < 0)
		error_closemlx_exit(ERRMSG_INSTANCE);
	mlx_set_instance_depth(&get_img_open()->instances[index], Z_IMG_OPEN);
	return (index);
}

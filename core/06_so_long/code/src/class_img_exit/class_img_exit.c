/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_img_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:56:23 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:56:42 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* private */
mlx_image_t	*class_img_exit(mlx_texture_t *texture)
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

void	set_texture_exit(char *file)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file);
	if (texture == NULL)
		error_closemlx_exit(ERRMSG_TEXTURE_EXIT);
	class_img_exit(texture);
}

mlx_image_t	*get_img_exit(void)
{
	return (class_img_exit(NULL));
}

int	new_instance_exit(int x, int y)
{
	int	index;

	index = mlx_image_to_window(get_mlx(), get_img_exit(), x, y);
	if (index < 0)
		error_closemlx_exit(ERRMSG_INSTANCE);
	mlx_set_instance_depth(&get_img_exit()->instances[index], Z_IMG_EXIT);
	return (index);
}

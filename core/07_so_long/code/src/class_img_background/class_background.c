/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:25:03 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 20:03:08 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/MLX42/include/MLX42/MLX42.h"
#include "../../include/so_long.h"

/* private */
mlx_image_t	*class_img_bg(mlx_texture_t *texture)
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

void	set_texture_bg(char *file)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file);
	if (texture == NULL)
		error_closemlx_exit(ERRMSG_TEXTURE_BG);
	class_img_bg(texture);
}

mlx_image_t	*get_img_bg(void)
{
	return (class_img_bg(NULL));
}

int	new_instance_bg(int x, int y)
{
	int	index;

	index = mlx_image_to_window(get_mlx(), get_img_bg(), \
	(get_img_bg()->width / 2) - (get_mlx()->width / 2), - \
	(get_img_bg()->height / 2) - (get_mlx()->height / 2));
	if (index < 0)
		error_closemlx_exit(ERRMSG_INSTANCE);
	mlx_set_instance_depth(&get_img_bg()->instances[index], Z_IMG_BG);
	return (index);
}

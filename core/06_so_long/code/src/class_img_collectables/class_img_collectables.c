/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_img_collectables.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:57:01 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:58:12 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/MLX42/include/MLX42/MLX42.h"
#include "../../include/so_long.h"

/* private */
mlx_image_t	*class_img_coll(mlx_texture_t *texture)
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

void	set_texture_coll(char *file)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file);
	if (texture == NULL)
		error_closemlx_exit(ERRMSG_TEXTURE_COLL);
	class_img_coll(texture);
}

mlx_image_t	*get_img_coll(void)
{
	return (class_img_coll(NULL));
}

int	new_instance_coll(int x, int y)
{
	int	index;

	index = mlx_image_to_window(get_mlx(), get_img_coll(), x, y);
	if (index < 0)
		error_closemlx_exit(ERRMSG_INSTANCE);
	mlx_set_instance_depth(&get_img_coll()->instances[index], Z_IMG_COLL);
	return (index);
}

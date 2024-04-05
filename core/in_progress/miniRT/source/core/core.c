/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:15:10 by groka             #+#    #+#             */
/*   Updated: 2024/03/20 18:37:08 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

/*
typedef struct s_core
{
	t_scene	*scene;
}	t_core;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_objnode	*objects;
}	t_scene;
*/

t_core	*get_core(void)
{
	static t_core	core;

	return (&core);
}

t_scene	*get_scene(void)
{
	return (&((*get_core()).scene));
}

t_ambient	*get_ambient(void)
{
	return (get_scene()->ambient);
}

t_camera	*get_camera(void)
{
	return (get_scene()->camera);
}

t_light	*get_light(void)
{
	return (get_scene()->light);
}

t_objnode	*get_objects(void)
{
	return (get_scene()->objects);
}

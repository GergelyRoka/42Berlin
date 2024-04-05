/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:01:29 by groka             #+#    #+#             */
/*   Updated: 2024/04/01 20:22:15 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <MLX42/MLX42.h>
//# include <libft/libft.h>"
# include "../lib/libft/libft.h"

# include "colors.h"
# include "tuples.h"

# define PI 3.14159265358979323846
# define EPSILON 0.00001
# define HEIGHT 540
# define WIDTH 960

typedef struct s_vec		t_vec;
typedef struct s_core		t_core;
typedef struct s_objnode	t_objnode;
typedef struct s_scene		t_scene;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_plane		t_plane;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef enum e_objtype		t_objtype;

typedef enum e_objtype
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_objtype;

typedef struct s_objnode
{
	t_objtype	type;
	void		*data;
	t_objnode	*next;
}	t_objnode;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_objnode	*objects;
}	t_scene;

typedef struct s_core
{
	t_scene	scene;
}	t_core;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

/**Ambient lightning:
A 0.2 255,255,255
∗ identifier: A
∗ ambient lighting ratio in range [0.0,1.0]: 0.2
∗ R,G,B colors in range [0-255]: 255, 255, 255
*/
typedef struct s_ambient
{
	double	ratio;
	t_vec	color;
}	t_ambient;

/** Camera:
C -50.0,0,20 0,0,1 70
∗ identifier: C
∗ x,y,z coordinates of the view point: -50.0,0,20
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
*/
typedef struct s_camera
{
	t_vec	coordinate;
	t_vec	normal_vector;
	double	fov;
}	t_camera;

/** Light:
L -40.0,50.0,0.0 0.6 10,0,255
∗ identifier: L
∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
∗ the light brightness ratio in range [0.0,1.0]: 0.6
∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/
typedef struct s_light
{
	t_vec	coordinate;
	double	diameter;
	t_vec	color;
}	t_light;

/** SPHERE
* sp 0.0,0.0,20.6 12.6 10,0,255
∗ identifier: sp
∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
∗ the sphere diameter: 12.6
∗ R,G,B colors in range [0-255]: 10, 0, 255
*/
typedef struct s_sphere
{
	t_vec	coordinate;
	double	diameter;
	t_vec	color;
}	t_sphere;

/** PLANE
* pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
∗ identifier: pl
∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
∗ R,G,B colors in range [0-255]: 0,0,225
*/
typedef struct s_plane
{
	t_vec	coordinate;
	t_vec	normal_vector;
	t_vec	color;
}	t_plane;

/** Cylinder
* cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
∗ identifier: cy
∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255
*/
typedef struct s_cylinder
{
	t_vec	coordinate;
	t_vec	normal_vector;
	double	diameter;
	double	height;
	t_vec	color;
}	t_cylinder;

#endif
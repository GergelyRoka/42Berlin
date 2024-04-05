/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:19:31 by groka             #+#    #+#             */
/*   Updated: 2024/04/02 18:16:18 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/canvas.h"
#include "../../include/tuples.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define FILENAME "canvas_to_ppm.ppm"

int float_to_int(float value) {
    // Scale the float value to fit within 0-255 range
    int scaled_value = (int)(value * 255.0f);

    // Ensure the value stays within the valid range
    if (scaled_value < 0) {
        return 0;
    } else if (scaled_value > 255) {
        return 255;
    } else {
        return scaled_value;
    }
}

void	canvas_to_ppm(t_color **canvas, int width, int height)
{
	FILE *f = fopen(FILENAME, "wb");
	int	i;
	int	j;

	if (!f)
	{
		printf("Error: Unable to open file\n");
		exit(1);
	}
	fprintf(f, "P3\n%d %d\n255\n", width, height);
	fclose (f);
	f = fopen(FILENAME, "a");
	j = height - 1;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			//printf("%f %f %f\n", canvas[i][j].red, canvas[i][j].green, canvas[i][j].blue);
			fprintf(f, "%i %i %i ", float_to_int(canvas[i][j].red),float_to_int(canvas[i][j].green) ,0);
			// if (j % 10 == 0)
			// 	fprintf(f, "\n");
			++i;
		}
		fprintf(f, "\n");
		++j;
	}
	fclose (f);
}


























	typedef struct s_environment
	{
		t_vector gravity;
		t_vector wind;
	} t_environment;


	typedef struct s_projectile
	{
		t_point position;
		t_vector velocity;
	} t_projectile;

	t_projectile tick(t_environment env, t_projectile proj)
	{
		t_projectile updated_proj;
		
		updated_proj.position = add_tuple_tuple(proj.position, proj.velocity);
		updated_proj.velocity = add_tuple_tuple(add_tuple_tuple(proj.velocity, env.gravity), env.wind);
		
		return updated_proj;
	};

void ft_cannon(t_color **canvas, int w, int h)
{
	static t_environment e = { 0, -0.1, 0, 0.0, -0.01, 0.0, 0.0, 0.0};
	static t_projectile p = { 1.0, 1.0, 0.0, 0.0, 1.0, 1.8, 0.0, 0.0 };
	p.velocity = multiply_tuple_double(((t_vector){1, 1.8, 0, 0}),5.25);
	static int tick_count = 0;
	static uint32_t color = 0;
	
	while (p.position.x > 0.0 && p.position.x < w && p.position.y > 0.0 && p.position.y < h)
	{

		p = tick(e, p);
		if ( p.position.x > 0 && p.position.y > 0 && p.position.x < w && p.position.y < h)
			canvas[(int)p.position.x ][h -(int)p.position.y] = (t_color){0.0, 0.5, 0.8};
			//mlx_put_pixel(image, p.position.x, HEIGHT - p.position.y, color);
		//printf("tick: %d, position: %f, %f, %f\n", tick_count, p.position.x, p.position.y, p.position.z);
		//printf("%f, %f, %f\n", p.position.x, p.position.y, p.position.z);
		tick_count++;
	}
}







int main(int argc, char const *argv[])
{
	t_color** arr;

	int w = 1024;
	int h = 512;

	arr = (t_color **)malloc(sizeof(t_color *) * w);
	for (int i = 0; i < w; i++)
	{
		arr[i] = (t_color *)malloc(sizeof(t_color) * h);
	}
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
	//		arr[i][j] = (t_color){(float)i / w, (float)j / h, 0};
			arr[i][j] = (t_color){10, 10, 10};

		}
	}
	ft_cannon(arr, w, h);
	canvas_to_ppm(arr, w, h);
}

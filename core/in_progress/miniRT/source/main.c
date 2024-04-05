/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:01:33 by groka             #+#    #+#             */
/*   Updated: 2024/04/02 16:12:37 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include "tuples.h"


#define WIDTH 1536
#define HEIGHT 720

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
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

void ft_cannon_hook(void* param)
{
	static t_environment e = { 0, -0.1, -0.01, 0.0, -0.05, 0.0, 0.0, 0.0};
	static t_projectile p = { 1.0, 1.0, 0.0, 0.1, 100.0, 50.0, 0.0, 0.0 };
	static int tick_count = 0;
	static uint32_t color = 0;
	
	// e.gravity = do_vector(0, -0.1, 0);
	// e.wind = do_vector(-0.01, 0, 0);
	
	// p.position = do_point(1, 1, 0);
	// p.velocity = (do_vector(5, 5, 0));
	
	(void)param;
	/*for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}*/
	//while (p.position.y > 0)
	//if (tick_count % 100 == 0)
	{

		p = tick(e, p);
		if ( p.position.x > 0 && p.position.y > 0 && p.position.x < WIDTH && p.position.y < HEIGHT)
			mlx_put_pixel(image, p.position.x, HEIGHT - p.position.y, color);
		else
		{
			 p.position.x = 100.0;
			 p.position.y = 50.0;
			 p.velocity.x = (rand()) % 1000 / 100.f ;
			 p.velocity.y = (rand()) % 1000 / 100.f;
			 color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				255  // A
			 );
			 //printf("out of bounds\n");
		}
		//printf("tick: %d, position: %f, %f, %f\n", tick_count, p.position.x, p.position.y, p.position.z);
		//printf("%f, %f, %f\n", p.position.x, p.position.y, p.position.z);
	}
		tick_count++;
}

int test()
{
	mlx_t*	mlx;

	
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
		{
			uint32_t color = ft_pixel(
				0, // R
				0, // G
				0, // B
				255  // A
			);
			mlx_put_pixel(image, x, y, color);
		}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	//mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_cannon_hook, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int test2()
{




	mlx_t*	mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


int main(int argc, char const *argv[])
{
	test();
	return (0);
}

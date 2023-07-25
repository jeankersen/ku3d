/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:14:48 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/25 15:02:31 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_cub *imo = (t_cub *) param;



	if (keydata.key == MLX_KEY_D && keydata.action ==  MLX_PRESS)
		{
			int x = imo->img->instances[0].x += 1;
			int y = imo->img->instances[0].y;
			mlx_delete_image(imo->mlx, imo->img);
			imo->img = mlx_new_image(imo->mlx, 1000, 1000);
			mlx_image_to_window(imo->mlx, imo->img, x, y);
			mlx_put_pixel(imo->img, x, y, 0xFFFFFFFF);
		}

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		{
			int x = imo->img->instances[0].x -= 1;
			int y = imo->img->instances[0].y;
			mlx_delete_image(imo->mlx, imo->img);
			imo->img = mlx_new_image(imo->mlx, 1000, 1000);
			mlx_image_to_window(imo->mlx, imo->img, x, y);
			mlx_put_pixel(imo->img, x, y, 0xFFFFFFFF);
		}


	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		{
			int y = imo->img->instances[0].y += 1;
			int x = imo->img->instances[0].x;
			mlx_delete_image(imo->mlx, imo->img);
			imo->img = mlx_new_image(imo->mlx, 1000, 1000);
			mlx_image_to_window(imo->mlx, imo->img, x, y);
			mlx_put_pixel(imo->img, x, y, 0xFFFFFFFF);
		}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		{
			int y = imo->img->instances[0].y -= 1;
			int x = imo->img->instances[0].x;
			mlx_delete_image(imo->mlx, imo->img);
			imo->img = mlx_new_image(imo->mlx, 1000, 1000);
			mlx_image_to_window(imo->mlx, imo->img, x, y);
			mlx_put_pixel(imo->img, x, y, 0xFFFFFFFF);
		}
}



static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{

	t_cub imo;
	// Start mlx
	imo.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!imo.mlx)
        error();


	imo.img = mlx_new_image(imo.mlx, 1000, 1000);

	// Display the image
	if (mlx_image_to_window(imo.mlx, imo.img, 0, 0) < 0)
        error();
	mlx_put_pixel(imo.img, 0, 0, 0xFF0000FF);
	mlx_key_hook(imo.mlx, &my_keyhook, &imo);
	mlx_loop(imo.mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	//mlx_delete_image(imo.mlx, imo.img);
	//mlx_terminate(imo.mlx);
	return (EXIT_SUCCESS);
}

/*

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");

	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}


// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();



	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 750, 500);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	//draw_square(img, 300);
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, mlx);
	draw_circle(img, 50, 50, 50);
	draw_line_bresenham(img, 100, 70, 300, 100);
	draw_line_dda(img, 150, 120, 350, 150);
	draw_triangles(img, 150, 100, 200, 250, 300, 70);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
*/


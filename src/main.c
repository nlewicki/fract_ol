/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:22:14 by nicolewicki       #+#    #+#             */
/*   Updated: 2025/02/25 10:43:54 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_fractol(t_fractol *fractol, int argc, char *argv[])
{
	if (argc != 2 && argc != 4)
	{
		ft_putendl_fd("Usage: ./fract_ol [m, j, ...] [cx] [cy]", 1);
		ft_error();
	}
	fractol->type = argv[1];
	check_args(fractol, argc, argv);
	fractol->zoom = HEIGHT / 4;
	fractol->mouse_x = 0;
	fractol->mouse_y = 0;
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->iter = 100;
	fractol->color = 0xFFFFFFFF;
	fractol->argc = argc;
	fractol->argv = argv;
	if (ft_strcmp(fractol->type, "b") == 0)
		setup_for_burningship(fractol);
	if (ft_strcmp(fractol->type, "m") == 0)
		setup_for_mandelbrot(fractol);
	if (ft_strcmp(fractol->type, "j") == 0)
		setup_for_julia(fractol);
}

int	calculate_fractol(t_fractol *fractol, t_complex *c, int x, int y)
{
	if (ft_strcmp(fractol->type, "m") == 0)
		return (calculate_mandelbrot(fractol, c));
	else if (ft_strcmp(fractol->type, "j") == 0)
		return (calculate_julia(fractol, x, y));
	else if (ft_strcmp(fractol->type, "b") == 0)
		return (calc_burning_ship(fractol, c));
	else
		ft_printf("\nbad fractol type\n");
	return (exit_fractol(fractol), 0);
}

int	draw_fractol(t_fractol *fractol)
{
	t_complex	c;
	int			iter;
	int			x;
	int			y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strcmp(fractol->type, "j") != 0)
			{
				c.real = (x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
				c.imag = (y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;
			}
			iter = calculate_fractol(fractol, &c, x, y);
			my_mlx_pixel_put(fractol->img, x, y,
				calc_color(iter, fractol->iter));
		}
	}
	if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
		return (1);
	return (0);
}

// void ft_leaks(void)
// {
// 	system("leaks fractol");
// }
// 	atexit(ft_leaks);
/*
-0.70176 -0.3842  // Lightning Shape
0.285 0.01        // Swirling Nebula
-0.8 0.156        // Burning Star
0.355 0.355       // Ghostly Web
-0.4 0.6          // Dark Spirals
-1.476 0.0        // Butterfly Wings
-0.75 0.11        // Electric Storm
*/

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	init_fractol(&fractol, argc, argv);
	mlx_set_setting(MLX_MAXIMIZED, false);
	fractol.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractol.mlx)
		return (1);
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.img
		|| (mlx_image_to_window(fractol.mlx, fractol.img, 0, 0) < 0))
		return (2);
	draw_fractol(&fractol);
	mlx_key_hook(fractol.mlx, key_hook, &fractol);
	mlx_scroll_hook(fractol.mlx, mouse_hook, &fractol);
	mlx_cursor_hook(fractol.mlx, cursor_hook, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}

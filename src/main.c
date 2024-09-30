/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:22:14 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/09/30 16:40:19 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

#define WIDTH 960
#define HEIGHT 540

int draw_fractal(t_fractol *fractol, char *type, double cx, double cy);

void put_color_to_pixel(t_fractol *fractol, int x, int y, int color)
{
    uint32_t *pixel = (uint32_t *)(fractol->image->pixels);
    pixel[y * WIDTH + x] = color;
}

void exit_fractal(t_fractol *fractol)
{
    ft_putendl_fd("Exiting...", 1);
    if (fractol->image)
        mlx_delete_image(fractol->mlx, fractol->image);
    if (fractol->mlx)
        mlx_terminate(fractol->mlx);
    exit(1);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fractol *fractol = (t_fractol *)param;

	if (key.key == MLX_KEY_ESCAPE)
		exit_fractal(fractol);
}

int main(int argc, char *argv[])
{
 	t_fractol	fractol;
	char 		*type;

	if (argc < 2 || argc > 4)
    {
        ft_putendl_fd("Usage: ./fract_ol [mandel, julia, ship] [cx] [cy]", 1);
        exit(1);
    }
	type = argv[1];
    fractol.cx = 0.285; 
    fractol.cy = 0.01;
    if (argc >= 3)
        fractol.cx = atof(argv[2]);
    if (argc == 4)
        fractol.cy = atof(argv[3]);
	printf("cx: %f, cy: %f\n", fractol.cx, fractol.cy);
	type = argv[1];
    fractol.mlx = mlx_init(WIDTH, HEIGHT, "Fract_ol", true);
    fractol.image = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
    fractol.zoom = 200;
    fractol.offset_x = -2.0;
    fractol.offset_y = -2.0;
    fractol.max_iterations = 100;
    fractol.color = 0xFCBE11;
    fractol.x = 0;
    fractol.y = 0;

    draw_fractal(&fractol,	type, fractol.cx, fractol.cy);

    // Show the image
    mlx_image_to_window(fractol.mlx, fractol.image, 0, 0);

    // Main loop
	mlx_key_hook(fractol.mlx, key_hook, &fractol);
    mlx_loop(fractol.mlx);
    // Cleanup
    mlx_delete_image(fractol.mlx, fractol.image);
    mlx_terminate(fractol.mlx);
    return (0);
}

int draw_fractal(t_fractol *fractol, char *type, double cx, double cy)
{
    fractol->x = 0;
    fractol->y = 0;
    while (fractol->x < WIDTH)
    {
        while (fractol->y < HEIGHT)
        {
            if (ft_strncmp(type, "mandel", 6) == 0)
                calculate_mandelbrot(fractol);
            else if (ft_strncmp(type, "julia", 5) == 0)
                calculate_julia(fractol, cx, cy);
            else
                exit_fractal(fractol);
            fractol->y++;
        }
        fractol->x++;
        fractol->y = 0;
    }
    return (0);
}

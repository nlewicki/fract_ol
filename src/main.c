/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:22:14 by nicolewicki       #+#    #+#             */
/*   Updated: 2025/02/14 12:58:54 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void my_mlx_pixel_put(mlx_image_t* img, int x, int y, int color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        mlx_put_pixel(img, x, y, color);
    }
}

void exit_fractol(t_fractol *fractol)
{
    ft_putendl_fd("Exiting...", 1);
    if (fractol->img)
        mlx_delete_image(fractol->mlx, fractol->img);
    if (fractol->mlx)
        mlx_terminate(fractol->mlx);
    exit(1);
}

static void ft_error(void)
{
	fprintf(stderr, "%s in mlx\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void    init_fractol(t_fractol *fractol, int argc, char *argv[])
{
    if (argc < 2 || argc > 4)
    {
        ft_putendl_fd("Usage: ./fract_ol [m(mandel), j(julia), ...] [cx] [cy]", 1);
        ft_error();
    }
    fractol->type = ft_strdup(argv[1]);
    fractol->zoom = HEIGHT / 4;
    fractol->mouse_x = 0;
    fractol->mouse_y = 0;
    fractol->offset_x = -0.5;  // Changed from -2
    fractol->offset_y = 0;     // Changed from -2
    fractol->iter = 100;       // Reduced from 256 for initial rendering
    fractol->color = 0xFFFFFFFF;  // Changed to start with full blue (RGBA)
}

// int redraw(t_fractol *fractol)


void	key_hook(mlx_key_data_t key, void *param)
{
	t_fractol *fractol = (t_fractol *)param;

	if (key.key == MLX_KEY_ESCAPE)
		exit_fractol(fractol);
    if (key.key == MLX_KEY_UP)
        fractol->offset_y += 0.1;
    if (key.key == MLX_KEY_DOWN)
        fractol->offset_y -= 0.1;
    if (key.key == MLX_KEY_LEFT)
        fractol->offset_x += 0.1;
    if (key.key == MLX_KEY_RIGHT)
        fractol->offset_x -= 0.1;
    if (key.key == MLX_KEY_EQUAL)
        fractol->zoom += 10;
    if (key.key == MLX_KEY_MINUS)
        fractol->zoom -= 10;
    if (key.key == MLX_KEY_SPACE)
        fractol->iter += 10;
    if (key.key == MLX_KEY_M && fractol->iter > 10)
        fractol->iter -= 10;
    draw_fractol(fractol);
}


#include <memory.h>

int main(int argc, char *argv[])
{
 	t_fractol	fractol;

    (void)argc;
    (void)argv;
    init_fractol(&fractol, argc, argv);
    mlx_set_setting(MLX_MAXIMIZED, false);
    fractol.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractol.mlx)
		return (1);
    fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
    if (!fractol.img || (mlx_image_to_window(fractol.mlx, fractol.img, 0, 0) < 0))
		return (2);
    draw_fractol(&fractol);
	mlx_key_hook(fractol.mlx, key_hook, &fractol);
    mlx_loop(fractol.mlx);
    return (0);
}

int calc_color(int iter, int max_iter, int start_color)
{
    t_color color;
    float t;

    if (iter == max_iter)
        return (0);  // Black for points in the set

    t = (float)iter / max_iter;
    color.r_s = ((start_color >> 24) & 0xFF) * t;
    color.g_s = ((start_color >> 16) & 0xFF) * t;
    color.b_s = ((start_color >> 8) & 0xFF) * t;

    return ((int)(color.r_s) << 16 | (int)(color.g_s) << 8 | (int)(color.b_s) | 0xFF);
}

void clear_window(mlx_image_t *img)
{
    memset(img->pixels, 0x00000000, img->width * img->height * sizeof(int32_t));
}

int draw_fractol(t_fractol *fractol)
{
    t_complex c;
    int iter;
    int x;
    int y;

    // clear_window(fractol->img);

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            c.real = (x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
            c.imag = (y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;
            iter = calculate_mandelbrot(fractol, &c);
            my_mlx_pixel_put(fractol->img, x, y, calc_color(iter, fractol->iter, fractol->color));
            // printf("x: %d, y: %d, iter: %d\n", x, y, iter);
        }
    }

    if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
        return (1);
    return (0);
}

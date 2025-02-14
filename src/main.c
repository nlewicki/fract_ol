/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:22:14 by nicolewicki       #+#    #+#             */
/*   Updated: 2025/02/14 13:13:06 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
    fractol->offset_x = -0.5;
    fractol->offset_y = 0;
    fractol->iter = 100;
    fractol->color = 0xFFFFFFFF;
}


// #include <memory.h>
// void clear_window(mlx_image_t *img)
// {
//     memset(img->pixels, 0x00000000, img->width * img->height * sizeof(int32_t));
// }

int draw_fractol(t_fractol *fractol)
{
    t_complex c;
    int iter;
    int x;
    int y;

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

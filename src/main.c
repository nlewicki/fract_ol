/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:22:14 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/10/05 19:57:27 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
    uint8_t *dst;

    dst = fractol->img->pixels + (y * fractol->img->width + x) * sizeof(int);
    *(unsigned int*)dst = color;
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

double smooth_color(double iter, double max_iter, double x, double y)
{
    if (iter < max_iter) {
        double log_zn = log(x*x + y*y) / 2.0;
        double nu = log(log_zn / log(2)) / log(2);
        return iter + 1 - nu;
    }
    return (iter);
}

int psychedelic_color(double t)
{
    double r = 0.5 + 0.5 * sin(3.0 * t);
    double g = 0.5 + 0.5 * sin(3.0 * t + 2.094);
    double b = 0.5 + 0.5 * sin(3.0 * t + 4.188);
    return (get_rgba((int)(r * 255), (int)(g * 255), (int)(b * 255), 255));
}

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
    {
        write(1, "right\n", 6);
        fractol->offset_x -= 0.1;
    }
    if (key.key == MLX_KEY_EQUAL)
        fractol->zoom += 10;
    if (key.key == MLX_KEY_MINUS)
        fractol->zoom -= 10;
    if (key.key == MLX_KEY_SPACE)
        fractol->max_iterations += 10;
    draw_fractol(fractol);
}
static void ft_error(void)
{
	fprintf(stderr, "%s in mlx\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void    init_fractol(t_fractol *fractol, int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
    {
        ft_putendl_fd("Usage: ./fract_ol [mandel, julia, ...] [cx] [cy]", 1);
        ft_error();
    }
	fractol->type = ft_strdup(argv[1]);
    fractol->cx = 0.7; 
    fractol->cy = 0.27015;
    fractol->offset_x = 0;
    fractol->offset_y = 0;
    fractol->max_iterations = 100;
    fractol->color = 0xFCBE11;
    fractol->zoom = 100;
    if (argc >= 3)
        fractol->cx = atof(argv[2]);
    if (argc == 4)
        fractol->cy = atof(argv[3]);
	printf("cx: %f, cy: %f\n", fractol->cx, fractol->cy);
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
    mlx_delete_image(fractol.mlx, fractol.img);
    mlx_terminate(fractol.mlx);
    return (0);
}

int draw_fractol(t_fractol *fractol)
{
    fractol->x = 0;
    fractol->y = 0;
    printf("Drawing fractal of type: %s\n", fractol->type); // Debugging type
    while (fractol->x < WIDTH)
    {
        while (fractol->y < HEIGHT)
        {
            if (ft_strncmp(fractol->type, "julia", 5) == 0)
                calculate_julia(fractol);
            else if (ft_strncmp(fractol->type, "mandel", 6) == 0)
                calculate_mandelbrot(fractol);
            else
                exit_fractol(fractol);
            fractol->y++;
        }
        fractol->x++;
        fractol->y = 0;
    }
    if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
        return (1);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:07 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/10/05 19:31:10 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void calculate_mandelbrot(t_fractol *fractol)
{
    int i;
    double x0 = (fractol->x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
    double y0 = (fractol->y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;
    double x = 0.0;
    double y = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;

    i = 0;
    while (x2 + y2 <= 4 && i < fractol->max_iterations)
    {
        y = 2 * x * y + y0;
        x = x2 - y2 + x0;
        x2 = x * x;
        y2 = y * y;
        i++;
    }

    if (i == fractol->max_iterations)
    {
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, 0x000000);
    }
    else
    {
        double zn = sqrt(x * x + y * y);
        double nu = log2(log2(zn) / log2(2.0)) / log2(2.0);
        double t = (i + 1 - nu) / fractol->max_iterations;
        
        int r = (int)(9 * (1 - t) * t * t * t * 255);
        int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, get_rgba(r, g, b, 255));
    }
}
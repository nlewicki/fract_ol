/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:07 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/10/05 20:00:07 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

#include "fract_ol.h"
#include <math.h>

void calculate_mandelbrot(t_fractol *fractol)
{
    double x0 = (fractol->x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
    double y0 = (fractol->y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;
    double x = 0.0;
    double y = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    int i;

    i = 0;
    while (i < fractol->max_iterations && (x2 + y2 <= 4.0))
    {
        y = 2 * x * y + y0;
        x = x2 - y2 + x0;
        x2 = x * x;
        y2 = y * y;
        i++;
    }

    double smooth_i = smooth_color(i, fractol->max_iterations, x, y);
    
    if (i == fractol->max_iterations)
    {
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, 0x000000);
    }
    else
    {
        double t = smooth_i / fractol->max_iterations;
        int color = psychedelic_color(20 * t);
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, color);
    }
}
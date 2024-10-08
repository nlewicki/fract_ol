/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:07 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/10/08 16:36:24 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

#include "fract_ol.h"
#include <math.h>

void    init_coords(t_coords *coords)
{
    coords->x0 = 0;
    coords->y0 = 0;
    coords->x = 0;
    coords->y = 0;
    coords->x2 = 0;
    coords->y2 = 0;
    coords->i = 0;
    coords->j = 0;
}

void calculate_mandelbrot(t_fractol *fractol)
{
    t_coords coords;
    init_coords(&coords);
    coords.x0 = (fractol->x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
    coords.y0 = (fractol->y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;

    coords.i = 0;
    while (coords.i < fractol->max_iterations && (coords.x2 + coords.y2 <= 4.0))
    {
        coords.y = 2 * coords.x * coords.y + coords.y0;
        coords.x = coords.x2 - coords.y2 + coords.x0;
        coords.x2 = coords.x * coords.x;
        coords.y2 = coords.y * coords.y;
        coords.i++;
    }

    double smooth_i = smooth_color(coords.i, fractol->max_iterations, coords.x, coords.y);
    
    if (coords.i == fractol->max_iterations)
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
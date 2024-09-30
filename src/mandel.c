/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:07 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/09/30 16:39:34 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void calculate_mandelbrot(t_fractol *fractol)
{
    int i;
    double x_temp;

    fractol->name = "mandel";
    i = 0;
    fractol->zx = 0.0;
    fractol->zy = 0.0;
    fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
    fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
    while (++i < fractol->max_iterations)
    {
        x_temp = fractol->zx * fractol->zx - fractol->zy * fractol->zy + fractol->cx;
        fractol->zy = 2.0 * fractol->zx * fractol->zy + fractol->cy;
        fractol->zx = x_temp;
        if (fractol->zx * fractol->zx + fractol->zy * fractol->zy >= 4.0)
            break;
    }
    if (i == fractol->max_iterations)
        put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
    else
        put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color * i));
}
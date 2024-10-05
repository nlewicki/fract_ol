/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:18 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/10/05 19:29:52 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void calculate_julia(t_fractol *fractol)
{
    int i;
    double tmp;
    double zx = (fractol->x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
    double zy = (fractol->y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;

    i = 0;
    while (i < fractol->max_iterations && (zx * zx + zy * zy < 4.0))
    {
        tmp = zx * zx - zy * zy + fractol->cx;
        zy = 2.0 * zx * zy + fractol->cy;
        zx = tmp;
        i++;
    }
    if (i == fractol->max_iterations)
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, 0x000000);
    else
    {
        double t = (double)i / fractol->max_iterations;
        int r = (int)(9 * (1 - t) * t * t * t * 255);
        int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, get_rgba(r, g, b, 255));
    }
}
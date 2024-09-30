/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:18 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/09/30 16:39:12 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void calculate_julia(t_fractol *fractol, double cx, double cy)
{
    int i;
    double tmp;

    fractol->name = "julia";
    fractol->cx = cx;
    fractol->cy = cy;
    fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
    fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
    i = 0;
    while (++i < fractol->max_iterations)
    {
        tmp = fractol->zx;
        fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy + fractol->cx;
        fractol->zy = 2 * fractol->zy * tmp + fractol->cy;
        if (fractol->zx * fractol->zx + fractol->zy * fractol->zy >= 4.0)
            break;
    }
    if (i == fractol->max_iterations)
        put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
    else
        put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color * (i % 255)));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:18 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/10/08 16:31:31 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void calculate_julia(t_fractol *fractol)
{
    t_coords    coords;
    double      tmp;
    double      t;
    
    coords.zx = (fractol->x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
    coords.zy = (fractol->y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;

    coords.i = 0;
    while (coords.i < fractol->max_iterations 
        && (coords.zx * coords.zx + coords.zy * coords.zy < 4.0))
    {
        tmp = coords.zx * coords.zx - coords.zy * coords.zy + fractol->cx;
        coords.zy = 2.0 * coords.zx * coords.zy + fractol->cy;
        coords.zx = tmp;
        coords.i++;
    }
    if (coords.i == fractol->max_iterations)
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, 0x000000);
    else
    {
        t = (double)coords.i / fractol->max_iterations;
        fractol->color = psychedelic_color(20 * t);
        mlx_put_pixel(fractol->img, fractol->x, fractol->y, fractol->color);
    }
}
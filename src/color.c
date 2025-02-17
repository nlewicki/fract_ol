/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:04:30 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/17 16:19:06 by nicolewicki      ###   ########.fr       */
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

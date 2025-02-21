/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:04:30 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/21 13:04:08 by nlewicki         ###   ########.fr       */
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
    (void)start_color;  // We won't use the start_color parameter

    if (iter == max_iter)
        return (0x000000FF);  // Black for points in the set

    t = (float)iter / max_iter;

    // Create a psychedelic rainbow effect
    if (t < 0.2) {
        // Purple to Blue
        color.r_s = (0.2 - t) * 5 * 255;
        color.g_s = 0;
        color.b_s = 255;
    }
    else if (t < 0.4) {
        // Blue to Cyan
        color.r_s = 0;
        color.g_s = (t - 0.2) * 5 * 255;
        color.b_s = 255;
    }
    else if (t < 0.6) {
        // Cyan to Green
        color.r_s = 0;
        color.g_s = 255;
        color.b_s = (0.6 - t) * 5 * 255;
    }
    else if (t < 0.8) {
        // Green to Yellow
        color.r_s = (t - 0.6) * 5 * 255;
        color.g_s = 255;
        color.b_s = 0;
    }
    else {
        // Yellow to Red
        color.r_s = 255;
        color.g_s = (1.0 - t) * 5 * 255;
        color.b_s = 0;
    }

    return ((int)(color.r_s) << 16 | (int)(color.g_s) << 8 | (int)(color.b_s) | 0xFF);
}

// int calc_color(int iter, int max_iter, int start_color)
// {
//     t_color color;
//     float t;

//     if (iter == max_iter)
//         return (0);  // Black for points in the set

//     t = (float)iter / max_iter;
//     color.r_s = ((start_color >> 24) & 0xFF) * t;
//     color.g_s = ((start_color >> 16) & 0xFF) * t;
//     color.b_s = ((start_color >> 8) & 0xFF) * t;

//     return ((int)(color.r_s) << 16 | (int)(color.g_s) << 8 | (int)(color.b_s) | 0xFF);
// }

// int calc_color(int iter, int max_iter, int start_color)
// {
//     t_color color;
//     (void)start_color;
//     float t;

//     if (iter == max_iter)
//         return (0x000000FF);  // Black for points in the set

//     t = (float)iter / max_iter;

//     // Create a fiery gradient
//     if (t < 0.3)
//     {
//         // Dark red to bright red
//         color.r_s = (t * 3.33) * 255;
//         color.g_s = 0;
//         color.b_s = 0;
//     }
//     else if (t < 0.6)
//     {
//         // Bright red to orange
//         color.r_s = 255;
//         color.g_s = ((t - 0.3) * 3.33) * 255;
//         color.b_s = 0;
//     }
//     else
//     {
//         // Orange to yellow highlights
//         color.r_s = 255;
//         color.g_s = 200;
//         color.b_s = ((t - 0.6) * 2.5) * 255;
//     }

//     return ((int)(color.r_s) << 16 | (int)(color.g_s) << 8 | (int)(color.b_s) | 0xFF);
// }

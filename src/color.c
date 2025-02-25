/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:04:30 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/25 10:36:36 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mlx_put_pixel(img, x, y, color);
	}
}

static void	calc_color2(float t, t_color *color)
{
	if (t < 0.4)
	{
		color->r_s = 0;
		color->g_s = (t - 0.2) * 5 * 255;
		color->b_s = 255;
	}
	else if (t < 0.6)
	{
		color->r_s = 0;
		color->g_s = 255;
		color->b_s = (0.6 - t) * 5 * 255;
	}
	else if (t < 0.8)
	{
		color->r_s = (t - 0.6) * 5 * 255;
		color->g_s = 255;
		color->b_s = 0;
	}
	else
	{
		color->r_s = 255;
		color->g_s = (1.0 - t) * 5 * 255;
		color->b_s = 0;
	}
}

int	calc_color(int iter, int max_iter)
{
	t_color	color;
	float	t;

	if (iter == max_iter)
		return (0x000000FF);
	t = (float)iter / max_iter;
	if (t < 0.2)
	{
		color.r_s = (0.2 - t) * 5 * 255;
		color.g_s = 0;
		color.b_s = 255;
	}
	else
		calc_color2(t, &color);
	return ((int)(color.r_s) << 16 | (int)(color.g_s) << 8
		| (int)(color.b_s) | 0xFF);
}

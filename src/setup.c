/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:20:37 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/25 10:33:37 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	setup_for_julia(t_fractol *fractol)
{
	fractol->zoom = HEIGHT / 4;
	fractol->type = "j";
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	if (fractol->argc != 4)
	{
		fractol->julia_real = -0.8;
		fractol->julia_imag = 0.156;
	}
}

void	setup_for_mandelbrot(t_fractol *fractol)
{
	fractol->zoom = HEIGHT / 4;
	fractol->type = "m";
	fractol->offset_x = -0.5;
	fractol->offset_y = 0;
}

void	setup_for_burningship(t_fractol *fractol)
{
	fractol->zoom = HEIGHT / 4;
	fractol->type = "b";
	fractol->offset_x = -0.5;
	fractol->offset_y = -0.5;
	fractol->color = 0xFF4169E1;
}

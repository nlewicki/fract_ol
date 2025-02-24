/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:20:37 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/24 11:49:25 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	setup_for_julia(t_fractol *fractol)
{
	fractol->type = "j";
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	if (fractol->argc == 4)
	{
		fractol->julia_real = atof(fractol->argv[2]);
		fractol->julia_imag = atof(fractol->argv[3]);
	}
	else
	{
		fractol->julia_real = -0.8;
		fractol->julia_imag = 0.156;
	}
}

void	setup_for_mandelbrot(t_fractol *fractol)
{
	fractol->type = "m";
	fractol->offset_x = -0.5;
	fractol->offset_y = 0;
}

void	setup_for_burningship(t_fractol *fractol)
{
	fractol->type = "b";
	fractol->offset_x = -0.5;
	fractol->offset_y = -0.5;
	fractol->color = 0xFF4169E1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:18 by nicolewicki       #+#    #+#             */
/*   Updated: 2025/02/24 11:54:20 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	calculate_julia(t_fractol *fractol, int x, int y)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = 0;
	z.real = (x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
	z.imag = (y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;
	while ((z.real * z.real + z.imag * z.imag) < 4 && i++ < fractol->iter)
	{
		real_temp = z.real * z.real - z.imag * z.imag + fractol->julia_real;
		z.imag = 2 * z.real * z.imag + fractol->julia_imag;
		z.real = real_temp;
	}
	return (i);
}

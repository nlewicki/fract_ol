/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:38:07 by nicolewicki       #+#    #+#             */
/*   Updated: 2025/02/24 11:57:43 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	calculate_mandelbrot(t_fractol *fractol, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = 0;
	z.real = 0;
	z.imag = 0;
	while ((z.real * z.real + z.imag * z.imag) < 4 && i++ < fractol->iter)
	{
		real_temp = z.real * z.real - z.imag * z.imag + c->real;
		z.imag = 2 * z.real * z.imag + c->imag;
		z.real = real_temp;
	}
	return (i);
}

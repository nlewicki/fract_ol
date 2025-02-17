/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Crealated: 2025/02/17 15:56:37 by nicolewicki       #+#    #+#             */
/*   Updated: 2025/02/17 15:57:21 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	calc_burning_ship(t_fractol *fractol, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.real = 0;
	z.imag = 0;
	while ((z.real * z.real + z.imag * z.imag) < 4 && ++i < fractol->iter)
	{
		real_temp = z.real * z.real - z.imag * z.imag + c->real;
		z.imag = fabs(2 * z.real * z.imag) + c->imag;
		z.real = fabs(real_temp);
	}
	return (i);
}
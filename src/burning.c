/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:56:00 by y nicolewic       #+#    #+#             */
/*   Updated: 2025/02/24 11:50:52 by nlewicki         ###   ########.fr       */
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
		z.real = fabs(z.real);
		z.imag = fabs(z.imag);
		real_temp = z.real * z.real - z.imag * z.imag + c->real;
		z.imag = 2 * z.real * z.imag + c->imag;
		z.real = real_temp;
	}
	return (i);
}

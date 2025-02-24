/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:55:54 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/24 13:56:31 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_error(void)
{
	exit(EXIT_FAILURE);
}

int	is_nan(float num)
{
	return (num != num);
}

void	check_args(t_fractol *fractol, int argc, char *argv[])
{
	if (argc == 4)
	{
		if (ft_strcmp(fractol->type, "j") == 0)
		{
			fractol->julia_real = ft_atof(argv[2]);
			fractol->julia_imag = ft_atof(argv[3]);
			if (is_nan(fractol->julia_real) || is_nan(fractol->julia_imag))
			{
				ft_printf("Error: Invalid input.\n");
				ft_printf("Format: ./fractol J <real> <imaginary>\n");
				ft_printf("Example: ./fractol j -0.8 0.156\n");
				ft_error();
			}
		}
		else
		{
			ft_printf("Error: Invalid input.\n");
			ft_error();
		}
	}
}

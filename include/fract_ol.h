/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:28:36 by nlewicki          #+#    #+#             */
/*   Updated: 2024/10/01 13:44:20 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/libft/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_fractol
{
	mlx_t *mlx;
	mlx_image_t *image;
	int zoom;
	double offset_x;
	double offset_y;
	int max_iterations;
	int color;
	int x;
	int y;
	double zx;
	double zy;
	double cx;
	double cy;
	char *name;
} t_fractol;

void calculate_mandelbrot(t_fractol *fractol);
void calculate_julia(t_fractol *fractol, double cx, double cy);
void put_color_to_pixel(t_fractol *fractol, int x, int y, int color);

#endif

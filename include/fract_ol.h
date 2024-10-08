/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:28:36 by nlewicki          #+#    #+#             */
/*   Updated: 2024/10/08 16:28:37 by nicolewicki      ###   ########.fr       */
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

#define WIDTH 720
#define HEIGHT 720

typedef struct s_fractol
{
	mlx_t* mlx;
	mlx_image_t* img;
	char *type;
	int zoom;
	double offset_x;
	double offset_y;
	int max_iterations;
	int color;
	int x;
	int y;
	double cx;
	double cy;
} t_fractol;

typedef struct s_coords
{
	double x;
	double y;
	double zx;
	double zy;
	double x0;
	double y0;
	double x2;
	double y2;
	int 	i;
	int 	j;
} t_coords;


double smooth_color(double iter, double max_iter, double x, double y);
int psychedelic_color(double t);
void my_mlx_pixel_put(mlx_image_t* img, int x, int y, int color);
int get_rgba(int r, int g, int b, int a);
int draw_fractol(t_fractol *fractol);
void calculate_mandelbrot(t_fractol *fractol);
void calculate_julia(t_fractol *fractol);

#endif

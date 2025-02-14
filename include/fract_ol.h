/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:28:36 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/14 12:20:28 by nlewicki         ###   ########.fr       */
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

#define WIDTH 800
#define HEIGHT 800

typedef struct s_color
{
	int r_s;
	int g_s;
	int b_s;
	int a_s;
}   t_color;

typedef struct s_window
{
	int pixel_len;
	int line_len;
	int endian;
} t_window;

typedef struct s_fractol
{
	mlx_t*			mlx;
	mlx_image_t*	img;
	t_window		window;
	char 			*type;
	int				zoom;
	double			offset_x;
	double			offset_y;
	double			mouse_x;
	double			mouse_y;
	u_int32_t		color;
	int				iter;
}	t_fractol;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;


void my_mlx_pixel_put(mlx_image_t* img, int x, int y, int color);
int draw_fractol(t_fractol *fractol);
int calculate_mandelbrot(t_fractol *fractol, t_complex *c);
void calculate_julia(t_fractol *fractol);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:08:14 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/17 15:44:22 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fract_ol.h"

#define WIDTH 500
#define HEIGHT 500
#define MIN_ZOOM 10
#define MAX_ITER 250
#define MIN_ITER 10

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

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	mlx_t*			mlx;
	mlx_image_t*	img;
	t_window		window;
	double			julia_real;
	double			julia_imag;
	char 			*type;
	int				zoom;
	double			old_zoom;
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


#endif

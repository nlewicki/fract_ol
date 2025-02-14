/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:28:36 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/14 13:12:26 by nlewicki         ###   ########.fr       */
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

# include "structs.h"

void exit_fractol(t_fractol *fractol);
void	key_hook(mlx_key_data_t key, void *param);
void my_mlx_pixel_put(mlx_image_t* img, int x, int y, int color);
int calc_color(int iter, int max_iter, int start_color);
int draw_fractol(t_fractol *fractol);
int calculate_mandelbrot(t_fractol *fractol, t_complex *c);
void calculate_julia(t_fractol *fractol);

#endif

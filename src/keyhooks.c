/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:04:24 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/24 12:09:34 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	exit_fractol(t_fractol *fractol)
{
	ft_putendl_fd("Exiting...", 1);
	if (fractol->img)
		mlx_delete_image(fractol->mlx, fractol->img);
	if (fractol->mlx)
		mlx_terminate(fractol->mlx);
	exit(1);
}

void	key_hook2(mlx_key_data_t key, t_fractol *fractol)
{
	if (key.key == MLX_KEY_1)
		setup_for_julia(fractol);
	else if (key.key == MLX_KEY_2)
		setup_for_mandelbrot(fractol);
	else if (key.key == MLX_KEY_3)
		setup_for_burningship(fractol);
	else
		return ;
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
		exit_fractol(fractol);
	else if (key.key == MLX_KEY_S)
		fractol->offset_y += 0.1;
	else if (key.key == MLX_KEY_W)
		fractol->offset_y -= 0.1;
	else if (key.key == MLX_KEY_D)
		fractol->offset_x += 0.1;
	else if (key.key == MLX_KEY_A)
		fractol->offset_x -= 0.1;
	else if (key.key == MLX_KEY_SPACE && fractol->iter < MAX_ITER)
		fractol->iter += 10;
	else if (key.key == MLX_KEY_M && fractol->iter > MIN_ITER)
		fractol->iter -= 10;
	else if (key.key == MLX_KEY_1 || key.key == MLX_KEY_2
		|| key.key == MLX_KEY_3)
		key_hook2(key, fractol);
	else
		return ;
	draw_fractol(fractol);
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*frac;
	double		zoom_factor;
	double		xbz;
	double		ybz;

	zoom_factor = 1.1;
	frac = (t_fractol *)param;
	(void)xdelta;
	xbz = (frac->mouse_x - WIDTH / 2.0) / frac->zoom + frac->offset_x;
	ybz = (frac->mouse_y - HEIGHT / 2.0) / frac->zoom + frac->offset_y;
	frac->old_zoom = frac->zoom;
	if (ydelta > 0)
		frac->zoom *= zoom_factor;
	else if (ydelta < 0)
		frac->zoom /= zoom_factor;
	if (frac->zoom < MIN_ZOOM)
		frac->zoom = MIN_ZOOM;
	if (frac->zoom != frac->old_zoom)
	{
		frac->offset_x = xbz - (frac->mouse_x - WIDTH / 2.0) / frac->zoom;
		frac->offset_y = ybz - (frac->mouse_y - HEIGHT / 2.0) / frac->zoom;
		draw_fractol(frac);
	}
}

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->mouse_x = xpos;
	fractol->mouse_y = ypos;
}

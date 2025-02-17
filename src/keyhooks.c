/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:04:24 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/17 15:10:50 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void exit_fractol(t_fractol *fractol)
{
    ft_putendl_fd("Exiting...", 1);
    if (fractol->img)
        mlx_delete_image(fractol->mlx, fractol->img);
    if (fractol->mlx)
        mlx_terminate(fractol->mlx);
    exit(1);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_fractol *fractol = (t_fractol *)param;

	if (key.key == MLX_KEY_ESCAPE)
		exit_fractol(fractol);
    else if (key.key == MLX_KEY_UP)
        fractol->offset_y += 0.1;
    else if (key.key == MLX_KEY_DOWN)
        fractol->offset_y -= 0.1;
    else if (key.key == MLX_KEY_LEFT)
        fractol->offset_x += 0.1;
    else if (key.key == MLX_KEY_RIGHT)
        fractol->offset_x -= 0.1;
    else if (key.key == MLX_KEY_SPACE && fractol->iter < MAX_ITER)
        fractol->iter += 10;
    else if (key.key == MLX_KEY_M && fractol->iter > MIN_ITER)
        fractol->iter -= 10;
    else
        return;
    draw_fractol(fractol);
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
    t_fractol *fractol = (t_fractol *)param;
    double zoom_factor = 1.1;
    double mouse_x_before_zoom;
    double mouse_y_before_zoom;

    (void)xdelta;
    
    // Convert mouse coordinates to fractal space before zoom
    mouse_x_before_zoom = (fractol->mouse_x - WIDTH / 2.0) / fractol->zoom + fractol->offset_x;
    mouse_y_before_zoom = (fractol->mouse_y - HEIGHT / 2.0) / fractol->zoom + fractol->offset_y;
    
    fractol->old_zoom = fractol->zoom;
    
    // Apply zoom based on scroll direction
    if (ydelta > 0)
        fractol->zoom *= zoom_factor;
    else if (ydelta < 0)
        fractol->zoom /= zoom_factor;
    
    if (fractol->zoom < MIN_ZOOM)
        fractol->zoom = MIN_ZOOM;
    
    if (fractol->zoom != fractol->old_zoom)
    {
        // Adjust offset to keep mouse position fixed in fractal space
        fractol->offset_x = mouse_x_before_zoom - (fractol->mouse_x - WIDTH / 2.0) / fractol->zoom;
        fractol->offset_y = mouse_y_before_zoom - (fractol->mouse_y - HEIGHT / 2.0) / fractol->zoom;
        
        // Redraw the fractal with new parameters
        draw_fractol(fractol);
    }
}

void cursor_hook(double xpos, double ypos, void *param)
{
    t_fractol *fractol = (t_fractol *)param;

    fractol->mouse_x = xpos;
    fractol->mouse_y = ypos;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:04:24 by nlewicki          #+#    #+#             */
/*   Updated: 2025/02/14 13:10:47 by nlewicki         ###   ########.fr       */
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
    if (key.key == MLX_KEY_UP)
        fractol->offset_y += 0.1;
    if (key.key == MLX_KEY_DOWN)
        fractol->offset_y -= 0.1;
    if (key.key == MLX_KEY_LEFT)
        fractol->offset_x += 0.1;
    if (key.key == MLX_KEY_RIGHT)
        fractol->offset_x -= 0.1;
    if (key.key == MLX_KEY_EQUAL)
        fractol->zoom += 10;
    if (key.key == MLX_KEY_MINUS)
        fractol->zoom -= 10;
    if (key.key == MLX_KEY_SPACE)
        fractol->iter += 10;
    if (key.key == MLX_KEY_M && fractol->iter > 10)
        fractol->iter -= 10;
    draw_fractol(fractol);
}

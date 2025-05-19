/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:59:39 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/23 20:35:16 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_close_win(t_fractal *fractal)
{
	ft_free_fractal(fractal);
	exit(0);
	return (0);
}

static void	ft_key_press_bonus(int keycode, t_fractal *fractal)
{
	if (keycode == 65362)
		fractal->offset_y -= 0.1 / fractal->zoom;
	else if (keycode == 65364)
		fractal->offset_y += 0.1 / fractal->zoom;
	else if (keycode == 65361)
		fractal->offset_x -= 0.1 / fractal->zoom;
	else if (keycode == 65363)
		fractal->offset_x += 0.1 / fractal->zoom;
	else if (keycode == 49)
		fractal->color_shift += 10;
	else if (keycode == 50)
		fractal->color_shift -= 10;
}

static int	ft_key_press(int keycode, t_fractal *fractal)
{
	if (keycode == 32)
		ft_close_win(fractal);
	ft_key_press_bonus(keycode, fractal);
	fractal->render_in_progress = 1;
	ft_render_frame(fractal);
	return (0);
}

void	ft_hook_key(t_fractal *fractal)
{
	mlx_hook(fractal->win, 17, 0L, (int (*)())ft_close_win, fractal);
	mlx_key_hook(fractal->win, ft_key_press, fractal);
}

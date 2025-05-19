/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:48:30 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/17 16:27:11 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	if (button == 4)
	{
		fractal->zoom *= zoom_factor;
		fractal->offset_x += (x - fractal->width / 2.0) / (fractal->width * \
				fractal->zoom) * (1 - 1 / zoom_factor);
		fractal->offset_y += (y - fractal->height / 2.0) / (fractal->height * \
				fractal->zoom) * (1 - 1 / zoom_factor);
	}
	else if (button == 5)
	{
		fractal->zoom /= zoom_factor;
		fractal->offset_x -= (x - fractal->width / 2.0) / (fractal->width * \
				fractal->zoom) * (1 - zoom_factor);
		fractal->offset_y -= (y - fractal->height / 2.0) / (fractal->height * \
				fractal->zoom) * (1 - zoom_factor);
	}
	fractal->render_in_progress = 1;
	ft_render_frame(fractal);
	return (0);
}

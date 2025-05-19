/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:10:16 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/23 19:10:14 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	ft_julia_z(t_complex z0, t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z = z0;
	while (ft_norm(z) < 2 && i < ITER)
	{
		z = ft_suite(z, c);
		i++;
	}
	return (i);
}

int	ft_set_color(int iter, int color_shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == ITER)
		return (0x000000);
	t = (double)iter / ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + color_shift) % 256;
	g = (g + color_shift * 2) % 256;
	b = (b + color_shift * 3) % 256;
	return ((r << 16) | (g << 8) | b);
}

t_complex	ft_conversion(int x, int y, t_fractal *fractal)
{
	t_complex	z;

	z.real = (x - fractal->width / 2.0) / (0.25 * \
	fractal->width * fractal->zoom) + fractal->offset_x;
	z.img = (y - fractal->height / 2.0) / (0.25 * \
	fractal->height * fractal->zoom) + fractal->offset_y;
	return (z);
}

int	ft_fractal_bs(t_complex z0, t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z = z0;
	while (ft_norm(z) < 2 && i < ITER)
	{
		z = ft_suite_bs(z, c);
		i++;
	}
	return (i);
}

int	ft_render_frame(t_fractal *fractal)
{
	void	*tmp;
	char	*tmp_data;

	if (!fractal->render_in_progress)
		return (0);
	if (fractal->type == 1)
		ft_draw_mandelbrot(fractal);
	else if (fractal->type == 2)
		ft_draw_julia(fractal);
	else if (fractal->type == 3)
		ft_draw_bs(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img_tmp, 0, 0);
	fractal->render_in_progress = 0;
	tmp = fractal->img;
	fractal->img = fractal->img_tmp;
	fractal->img_tmp = tmp;
	tmp_data = fractal->addr;
	fractal->addr = fractal->tmp_addr;
	fractal->tmp_addr = tmp_data;
	return (0);
}

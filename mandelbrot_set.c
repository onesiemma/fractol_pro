/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:56:08 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/17 16:55:21 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mand_c(t_complex c)
{
	int			iter;
	t_complex	z0;

	z0.real = 0;
	z0.img = 0;
	iter = ft_julia_z(z0, c);
	return (iter);
}

static int	ft_conv_pix_to_com_mand(int x, int y, t_fractal *fractal)
{
	int			iter;

	fractal->c = ft_conversion(x, y, fractal);
	iter = ft_mand_c(fractal->c);
	return (iter);
}

void	ft_draw_mandelbrot(t_fractal *fractal)
{
	int		x;
	int		y;
	int		iter;
	int		color;
	char	*pixel;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			iter = ft_conv_pix_to_com_mand(x, y, fractal);
			color = ft_set_color(iter, fractal->color_shift);
			pixel = fractal->tmp_addr + (y * fractal->size_line + x * \
			(fractal->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

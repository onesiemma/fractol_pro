/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:32:34 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/17 16:53:51 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_conv_pix_to_com_jul(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			iter;

	z = ft_conversion(x, y, fractal);
	iter = ft_julia_z(z, fractal->c);
	return (iter);
}

void	ft_draw_julia(t_fractal *fractal)
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
			iter = ft_conv_pix_to_com_jul(x, y, fractal);
			color = ft_set_color(iter, fractal->color_shift);
			pixel = fractal->tmp_addr + \
			(y * fractal->size_line + x * (fractal->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

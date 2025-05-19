/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:19:21 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/23 20:29:11 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_fractal(t_fractal *fractal)
{
	if (!fractal)
		return ;
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->img_tmp)
		mlx_destroy_image(fractal->mlx, fractal->img_tmp);
	free(fractal);
}

static void	ft_alloc_win(t_fractal *fractal, char *s)
{
	fractal->win = mlx_new_window(fractal->mlx, fractal->width, \
				fractal->height, s);
	if (!fractal->win)
	{
		ft_free_fractal(fractal);
		return ;
	}
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	if (!fractal->img)
	{
		ft_free_fractal(fractal);
		return ;
	}
	fractal->img_tmp = mlx_new_image(fractal->mlx, fractal->width, \
				fractal->height);
	if (!fractal->img_tmp)
	{
		ft_free_fractal(fractal);
		return ;
	}
}

void	ft_alloc_fractal(t_fractal *fractal, char *s)
{
	ft_alloc_win(fractal, s);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp, \
			&fractal->size_line, &fractal->endian);
	if (!fractal->addr)
	{
		ft_free_fractal(fractal);
		return ;
	}
	fractal->tmp_addr = mlx_get_data_addr(fractal->img_tmp, \
			&fractal->bpp, &fractal->size_line, &fractal->endian);
	if (!fractal->tmp_addr)
	{
		ft_free_fractal(fractal);
		return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:03:50 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/17 16:17:44 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_bs_c(t_complex c)
{
	int			iter;
	t_complex	z0;

	z0.real = 0;
	z0.img = 0;
	iter = ft_fractal_bs(z0, c);
	return (iter);
}

static int	ft_conv_pix_to_com_bs(int x, int y, t_fractal *fractal)
{
	int			iter;

	fractal->c = ft_conversion(x, y, fractal);
	iter = ft_bs_c(fractal->c);
	return (iter);
}

void	ft_draw_bs(t_fractal *fractal)
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
			iter = ft_conv_pix_to_com_bs(x, y, fractal);
			color = ft_set_color(iter, fractal->color_shift);
			pixel = fractal->tmp_addr + (y * fractal->size_line + \
					x * (fractal->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

// void	ft_bs_set(void *mlx, void *win, void *img)
// {
// 	char	*img_fractal;
// 	int		bpp;
// 	int		size_line;
// 	int		endian;

// 	img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
// 	ft_image_color_bs(img_data, bpp, size_line);
// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// 	mlx_destroy_image(mlx, img);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, WIDTH, HEIGHT, "burning_ship_set");
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	ft_bs_set(mlx, win, img);
// 	mlx_loop(mlx);
// 	return (0);
// }

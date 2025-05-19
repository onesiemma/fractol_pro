/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:31:02 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/17 16:53:21 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	ft_init_fractal_julia(t_fractal *fractal, char *s, t_complex z)
{
	fractal->height = HEIGHT;
	fractal->width = WIDTH;
	fractal->type = 2;
	fractal->c.real = z.real;
	fractal->c.img = z.img;
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->max_iter = ITER;
	fractal->current_iter = 0;
	fractal->render_in_progress = 0;
	fractal->color_shift = 0;
	ft_alloc_fractal(fractal, s);
}

static void	ft_init_fractal_mand_bs(t_fractal *fractal, char *s)
{
	if (ft_strcmp("Mandelbrot", s) == 0)
		fractal->type = 1;
	else if (ft_strcmp("BS", s) == 0)
		fractal->type = 3;
	fractal->height = HEIGHT;
	fractal->width = WIDTH;
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->max_iter = ITER;
	fractal->current_iter = 0;
	fractal->render_in_progress = 0;
	fractal->color_shift = 0;
	ft_alloc_fractal(fractal, s);
}

int	ft_fractal_type(char *s)
{
	if (ft_strcmp("Mandelbrot", s) == 0)
		return (1);
	else if (ft_strcmp("BS", s) == 0)
		return (3);
	else if (ft_strcmp("Julia", s) == 0)
		return (2);
	return (0);
}

t_fractal	*ft_init_fractal(char **argv, int argc)
{
	t_fractal	*fractal;
	t_complex	c;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		return (NULL);
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		ft_free_fractal(fractal);
		return (NULL);
	}
	if (argc == 2)
		ft_init_fractal_mand_bs(fractal, argv[1]);
	else if (argc == 4)
	{
		c = ft_c_julia(argv[2], argv[3]);
		ft_init_fractal_julia(fractal, argv[1], c);
	}
	return (fractal);
}

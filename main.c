/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:53:07 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/23 19:54:19 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_write_param(char **argv, int argc)
{
	int	i;

	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_printf(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}

int	ft_correct_arg(char	**argv, int argc)
{
	if (argc == 2 && ft_strcmp("Julia", argv[1]))
		return (ft_fractal_type(argv[1]));
	else if (argc == 4 && ft_strcmp("Julia", argv[1]) == 0)
	{
		if (ft_is_number(argv[2]) && ft_is_number(argv[3]))
			return (ft_fractal_type(argv[1]));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (ft_correct_arg(argv, argc) == 0)
	{
		ft_write_param(argv, argc);
		return (1);
	}
	fractal = ft_init_fractal(argv, argc);
	if (!fractal)
		return (1);
	fractal->render_in_progress = 1;
	ft_render_frame(fractal);
	ft_hook_key(fractal);
	mlx_mouse_hook(fractal->win, handle_mouse, fractal);
	mlx_loop(fractal->mlx);
	ft_free_fractal(fractal);
	return (0);
}

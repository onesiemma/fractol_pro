/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:31:45 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/17 17:00:07 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double	ft_norm(t_complex z)
{
	double	r;

	r = sqrt(pow(z.img, 2) + pow(z.real, 2));
	return (r);
}

t_complex	ft_complex2(t_complex z)
{
	t_complex	z2;

	z2.real = pow(z.real, 2) - pow(z.img, 2);
	z2.img = 2 * z.real * z.img;
	return (z2);
}

t_complex	ft_complex_bs(t_complex z)
{
	t_complex	z2;

	z2.real = pow(fabs(z.real), 2) - pow(fabs(z.img), 2);
	z2.img = 2 * fabs(z.real) * fabs(z.img);
	return (z2);
}

t_complex	ft_suite(t_complex z, t_complex c)
{
	t_complex	z_n;
	t_complex	z_n1;

	z_n = ft_complex2(z);
	z_n1.real = z_n.real + c.real;
	z_n1.img = z_n.img + c.img;
	return (z_n1);
}

t_complex	ft_suite_bs(t_complex z, t_complex c)
{
	t_complex	z_n;
	t_complex	z_n1;

	z_n = ft_complex_bs(z);
	z_n1.real = z_n.real + c.real;
	z_n1.img = z_n.img + c.img;
	return (z_n1);
}

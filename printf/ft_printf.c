/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:33:38 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/18 16:55:28 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convension(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(args, int)));
	if (c == 's')
		return (ft_printf_s(va_arg(args, char *)));
	if (c == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	if (c == 'x' || c == 'X')
		return (ft_printf_xx(va_arg(args, unsigned int), c));
	if (c == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'd' || c == 'i')
		return (ft_printf_di(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len += convension(str[i], args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

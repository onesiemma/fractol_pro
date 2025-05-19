/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:44 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/18 16:55:25 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nbase(int long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_nbase(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_printf_xx(unsigned int n, char c)
{
	int	len;

	if (c == 'x')
		len = ft_put_nbase(n, "0123456789abcdef");
	else
		len = ft_put_nbase(n, "0123456789ABCDEF");
	return (len);
}

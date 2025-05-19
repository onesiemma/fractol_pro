/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:59:41 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/18 16:54:57 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nbase(unsigned long num, char *base)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_put_nbase(num / 16, base);
	len += ft_putchar (base[num % 16]);
	return (len);
}

int	ft_printf_p(void *p)
{
	int	len;

	len = 0;
	if (!p)
		return (ft_putstr("0x0"));
	len += ft_putstr("0x");
	len += ft_put_nbase((unsigned long)p, "0123456789abcdef");
	return (len);
}

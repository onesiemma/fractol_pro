/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:27:02 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/18 16:55:31 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);

int	ft_printf_xx(unsigned int n, char c);
int	ft_printf_di(int nb);
int	ft_printf_p(void *p);
int	ft_printf_s(char *str);
int	ft_printf_u(unsigned int nb);
int	ft_printf_c(char c);
int	ft_printf(const char *str, ...);

#endif

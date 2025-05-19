/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:24:03 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/08 11:31:33 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	printf("%d\n", ft_isdigit('8'));
	printf("%d\n", ft_isdigit('8'));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", isdigit('0'));
	printf("%d\n", ft_isdigit('g'));
	printf("%d\n", isdigit('g'));
	return (0);
}
*/

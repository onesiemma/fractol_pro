/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:08:36 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/08 11:23:32 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main()
{
	printf("%d\n", ft_isalpha('g'));
	printf("%d\n", isalpha('g'));
	printf("%d\n", ft_isalpha('+'));
	printf("%d\n", isalpha('+'));
	printf("%d\n", ft_isalpha('n'));
	printf("%d\n", isalpha('n'));
	printf("%d\n", ft_isalpha('o'));
	printf("%d\n", isalpha('o'));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:18:21 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:51:05 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	unsigned char	*str;

	str = (unsigned char *)b;
	a = (unsigned char)c;
	while (len > 0)
	{
		*str = a;
		str++;
		len--;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char buffer[50];
	char buffer2[50];

	ft_memset(buffer, 0, sizeof(buffer));
	printf("Le buffer après ft_memset : '%s'\n", buffer);
	ft_memset(buffer, 'A', 10);
	printf("Le buffer après ft_memset : '%s'\n", buffer);
	memset(buffer2, 0, sizeof(buffer2));
	printf("Le buffer2 après memset : '%s'\n", buffer2);
	memset(buffer2, 'A', 10);
	printf("Le buffer2 après memset : '%s'\n", buffer2);

	return (0);
}
*/

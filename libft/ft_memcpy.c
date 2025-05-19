/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:46:41 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:50:11 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (dst == 0 && src == 0)
		return (0);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		source++;
		n--;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int	main(void)
{
	char src[] = "Hello, World!";
	char dest[50];
	char dest2[50];

	ft_memcpy(dest, src, 5);
	dest[13] = '\0';
	memcpy(dest2, src, 5);
	dest2[13] = '\0';

	printf("ma fonction: %s\n", dest);
	printf("du systeme: %s\n", dest2);

	return (0);
}
*/

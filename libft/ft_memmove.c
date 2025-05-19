/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:37:02 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/16 13:59:36 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(unsigned char *a, const unsigned char *b, size_t n)
{
	size_t	i;

	if (a > b)
	{
		i = n;
		while (i > 0)
		{
			i--;
			a[i] = b[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (len == 0)
		return (dst);
	if (!src && !dst)
		return (0);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	ft_copy(dest, source, len);
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	src1[20] = "Hello Emmanuelle";
	char	*dest1 = 0;
	char	*dest2 = 0;
	
	ft_memmove(dest1, src1, 5);
	memmove(dest2, src1, 5);
	printf("Après ft_memmove: src1 = %s, dest1 = %s\n", src1, dest1);
	printf("Après memmove: src1 = %s, dest2 = %s\n", src1, dest2);
	return (0);
}
*/

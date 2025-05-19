/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:57:39 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:25 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (fstrlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (fstrlen(src));
}
/*
#include <stdio.h>
#include <string.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
static size_t ft_strlen(const char *str);

int main(void)
{
    char src[] = "Hello, World!";
    char dst[20];
    size_t len1;
    char dst2[5];
    size_t len2;
    char dst3[10];
    size_t len3;
	char src1[] = "Hello, World!";
    char dst1[20];
    size_t len11;
    char dst21[5];
    size_t len21;
    char dst31[10];
    size_t len31;

    len1 = ft_strlcpy(dst, src, sizeof(dst));
    printf("Test 1: dst = \"%s\", Length = %zu\n", dst, len1);

    len2 = ft_strlcpy(dst2, src, sizeof(dst2));
    printf("Test 2: dst2 = \"%s\", Length = %zu\n", dst2, len2);

    len3 = ft_strlcpy(dst3, src, 0);
    printf("Test 3: dst3 = \"%s\", Length = %zu\n", dst3, len3);

	len11 = strlcpy(dst1, src1, sizeof(dst1));
    printf("Test 1: dst = \"%s\", Length = %zu\n", dst1, len11);

    len21 = ft_strlcpy(dst21, src1, sizeof(dst21));
    printf("Test 2: dst2 = \"%s\", Length = %zu\n", dst21, len21);

    len31 = ft_strlcpy(dst31, src1, 0);
    printf("Test 3: dst3 = \"%s\", Length = %zu\n", dst31, len31);


    return 0;
}
*/

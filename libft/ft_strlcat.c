/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 06:58:01 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:53:29 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = str_len(dst);
	src_len = str_len(src);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dest_len + i < dstsize - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < dstsize)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <string.h>
#include <stdio.h>
int main() {
    char dest[20] = "Hello, ";
    char *src = "World!";

    size_t result = ft_strlcat(dest, src, str_len(dest));
	size_t r = strlcat(dest, src, str_len(dest));

    printf("Resulting string: %s\n", dest);
    printf("Total length of the string %zu\n", result);
	printf("avec le syst: %zu\n", r);

    return 0;
}
*/

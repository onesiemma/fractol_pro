/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:03:24 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:12:14 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}
/*
#include <stdio.h>
#include <strings.h>
int	main(void)
{
	char buffer[50];

	for (int i = 0; i < 50; i++) {
		buffer[i] = 'A';
	}

	ft_bzero(buffer, 10);

	for (int i = 0; i < 50; i++) {
		if (buffer[i] == 0)
			printf("NULL ");
		else
			printf("%c ", buffer[i]);
	}
	printf("\n");
	char buffer2[50];

	for (int i = 0; i < 50; i++) {
		buffer2[i] = 'A';
	}

	bzero(buffer2, (10));

	for (int i = 0; i < 50; i++) {
		if (buffer2[i] == 0)
			printf("NULL ");
		else
			printf("%c ", buffer2[i]);
	}
	printf("\n");

	return (0);
}
*/

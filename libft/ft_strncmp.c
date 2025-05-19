/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 05:59:09 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/16 14:19:23 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char *s1 = 0;
	char *s2 = 0;
	char *s3 = "man";
	char *s4 = "Maman je veux";
	printf("test 1: %d\n", ft_strncmp(s1, s2, 6));
	printf("avec la fct du syst: %d\n", strncmp(s1, s2, 6));
	printf("test 2: %d\n", ft_strncmp(s1, s3, 6));
	printf("avec la fct du syst: %d\n", strncmp(s1, s3, 6));
	printf("test 3: %d\n", ft_strncmp(s1, s4, 5));
	printf("avec la fct du syst: %d\n", strncmp(s1, s4, 5));
	return 0;
}
*/

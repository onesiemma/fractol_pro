/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 01:41:05 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 16:14:41 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
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
/*
#include <stdio.h>
int	main()
{
	int lon;
	char *c = "maman je t'aime";

	lon = ft_strlen(c);
	printf("Le nombre de caracteres de la phrase %s est: %d", c, lon);
	return 0;
}
*/

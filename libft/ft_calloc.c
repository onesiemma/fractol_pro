/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:02:06 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:12:47 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	longueur;
	size_t	i;

	longueur = count * size;
	if (count == 0 || size == 0)
		longueur = 1;
	ptr = malloc(longueur);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < longueur)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

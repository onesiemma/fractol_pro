/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:29:14 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:35:32 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		if (n == -2147483648)
			return (11);
		n = -n;
	}
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	ft_unite(int n)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	c = nb % 10 + '0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*nbre;
	int		i;
	long	nb;

	nb = n;
	i = ft_len(nb);
	nbre = (char *)malloc((i + 1) * sizeof(char));
	if (!nbre)
		return (0);
	if (nb < 0)
	{
		nbre[0] = '-';
		nb = -nb;
	}
	nbre[i] = '\0';
	if (nb == 0)
		nbre[0] = '0';
	while (nb > 0)
	{
		nbre[i - 1] = ft_unite(nb);
		i--;
		nb = nb / 10;
	}
	return (nbre);
}
/*
#include <stdio.h>

int	main()
{
	long	n = -2147483648;
	int	nb = 0;

	printf ("%s\n", ft_itoa(n));
	printf("%s\n", ft_itoa(nb));
	return (0);
}
*/

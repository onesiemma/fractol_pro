/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:19:59 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 16:25:44 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fstrlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_null(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*chaine;

	if (!s)
		return (0);
	len_s = fstrlen(s);
	if (start >= len_s)
		return (ft_null());
	if (len > len_s - start)
		len = len_s - start;
	chaine = (char *) malloc((len + 1) * sizeof(char));
	if (!chaine)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		chaine[i] = s[start + i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = "Hello, World!";
	char *substr;

	substr = ft_substr(s, 7, 5);
	printf("Sous-chaîne : %s\n", substr);

	free(substr);

	return 0;
}
*/

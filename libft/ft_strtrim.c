/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:17:31 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 16:25:16 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fstrlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_commun(char c, const char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_elimine(const char *s, const char *sep, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (ft_commun(s[i], sep) == 1)
			i++;
	}
	else if (n == 1)
	{
		i = fstrlen(s) - 1;
		while (ft_commun(s[i], sep) == 1)
			i--;
	}
	return (i);
}

static	char	*ft_trim(char const *s, int start, int end)
{
	char	*str;
	int		k;

	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (0);
	k = 0;
	while (start <= end)
	{
		str[k] = s[start];
		k++;
		start++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*empty_str;

	if (!s1)
		return (0);
	if (!set)
	{
		k = fstrlen(s1) - 1;
		return (ft_trim(s1, 0, k));
	}
	i = ft_elimine(s1, set, 0);
	j = ft_elimine(s1, set, 1);
	if (i > j)
	{
		empty_str = (char *)malloc(1);
		if (!empty_str)
			return (0);
		empty_str[0] = '\0';
		return (empty_str);
	}
	return (ft_trim(s1, i, j));
}
/*
#include <stdio.h>

int main(void)
{
    char *s1 = "    Hello, World !    ";
    char *set = " " ;
    char *result;

    result = ft_strtrim(s1, set);
    printf("Trimmed string: '%s'\n", result);
    free(result);
    return 0;
}
*/

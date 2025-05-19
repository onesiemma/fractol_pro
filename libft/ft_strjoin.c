/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:16:29 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 16:21:30 by ombatkam         ###   ########.fr       */
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

static char	*ft_strcpy(char *dest, const char *src)
{
	char	*final_dest;

	final_dest = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (final_dest);
}

static char	*fstrdup(const char *src)
{
	char	*str;
	size_t	len;

	if (src == NULL)
		return (NULL);
	len = fstrlen(src) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strcpy(str, src);
	return (str);
}

static char	*ft_strcat(char *dest, const char *src)
{
	char	*final_dest;

	final_dest = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (final_dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (fstrdup(s2));
	if (!s2)
		return (fstrdup(s1));
	len_s1 = fstrlen(s1);
	len_s2 = fstrlen(s2);
	result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Erreur d'allocation mémoire\n");
    }

    return 0;
}
*/

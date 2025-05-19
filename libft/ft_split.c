/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:42:09 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/15 15:52:18 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbre_c(const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

static int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_mot(const char *s, char c)
{
	char	*mot;
	int		i;
	int		len;

	len = ft_len(s, c);
	mot = (char *)malloc((len + 1) * sizeof(char));
	if (!mot)
		return (0);
	i = 0;
	while (i < len)
	{
		mot[i] = s[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

static char	**ft_free_split(char **chaine)
{
	int	i;

	i = 0;
	while (chaine[i])
	{
		free(chaine[i]);
		i++;
	}
	free(chaine);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**chaine;
	int		i;

	if (!s)
		return (0);
	chaine = (char **)malloc((ft_nbre_c(s, c) + 1) * sizeof(char *));
	if (!chaine)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			chaine[i] = ft_mot(s, c);
			if (!chaine[i])
				return (ft_free_split(chaine));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	chaine[i] = 0;
	return (chaine);
}
/*
#include <stdio.h>
int	main()
{
	char	*s = "ooooobonjour omaman oje oveux omanger";
	char	t = 'o';
	char	**str = ft_split(s, t);
	int		i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
*/

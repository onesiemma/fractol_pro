/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:33:59 by ombatkam          #+#    #+#             */
/*   Updated: 2024/12/23 18:36:43 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_point(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_str_decimal(const char *s)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	j;

	len = ft_strlen(s);
	i = ft_point(s) + 1;
	str = (char *)malloc((len - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (i < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

static double	ft_number_c(const char *s)
{
	double	c;
	char	*str;
	size_t	len;
	int		x;

	str = ft_str_decimal(s);
	if (!str)
		return (0);
	len = ft_strlen(str);
	x = ft_atoi(s);
	if (x > 0)
		c = (double)x + (ft_atoi(str) / pow(10, len));
	else if (x < 0)
		c = (double)x - (ft_atoi(str) / pow(10, len));
	else
	{
		if (s[0] == '-')
			c = (double)x - (double)(ft_atoi(str) / pow(10, len));
		else
			c = (double)x + (double)(ft_atoi(str) / pow(10, len));
	}
	free(str);
	return (c);
}

int	ft_is_number(const char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_point(s);
	if (s[0] == '-')
		i++;
	while (i < j)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	i = j + 1;
	while (i < ft_strlen(s))
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

t_complex	ft_c_julia(const char *s1, const char *s2)
{
	t_complex	c;

	if (ft_is_number(s1) && ft_is_number(s2))
	{
		c.img = ft_number_c(s2);
		c.real = ft_number_c(s1);
	}
	return (c);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	// const char	*str = "-1.56";
// 	// const char	*s1 = "0.56";
// 	t_complex	c;
// 	c = ft_c_julia(argv[1], argv[2]);
// 	if (!ft_is_number(argv[1]) || !ft_is_number(argv[2]))
// 	{
// 		printf("erreurs de nombre");
// 		return (1);
// 	}
// 	printf("Valeur : %f\n", c.real);
// 	printf("decimale : %f\n", c.img);
// 	// if (ft_correct_arg(argv, argc) == 0)
// 	// 	ft_write_param(argv, argc);
// 	// else
// 	// 	printf("type %d", ft_correct_arg(argv, argc));
// 	return (0);
// }

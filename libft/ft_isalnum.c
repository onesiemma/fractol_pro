/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:55 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/08 11:42:07 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') \
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main() {
    // Tests de la fonction
    char test1 = 'A';
    char test2 = 'z';
    char test3 = '5';
    char test4 = '#';

    printf("ft_isalnum('%c') = %d\n", test1, ft_isalnum(test1)); 
	printf("ft_isalnum('%c') = %d\n", test2, ft_isalnum(test2));
	printf("ft_isalnum('%c') = %d\n", test3, ft_isalnum(test3)); 
	printf("ft_isalnum('%c') = %d\n", test4, ft_isalnum(test4)); 
	printf("ft_isalnum('%c') = %d\n", test1, isalnum(test1)); 
	printf("ft_isalnum('%c') = %d\n", test2, isalnum(test2)); 
	printf("ft_isalnum('%c') = %d\n", test3, isalnum(test3)); 
	printf("ft_isalnum('%c') = %d\n", test4, isalnum(test4)); 

    return 0;
}
*/

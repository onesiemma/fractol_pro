/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:42:48 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/08 11:52:06 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
/*
#include <stdio.h>
#include <ctype.h>
int main() {
    
	int test1 = 'A'; 
    int test2 = 'z';    
    int test3 = '5';    
    int test4 = 128;    
    int test5 = -1;     

    printf("ft_isascii('%c') = %d\n", test1, ft_isascii(test1)); 
    printf("ft_isascii('%c') = %d\n", test2, ft_isascii(test2)); 
    printf("ft_isascii('%c') = %d\n", test3, ft_isascii(test3)); 
    printf("ft_isascii(128) = %d\n", ft_isascii(test4)); 
	printf("ft_isascii(-1) = %d\n", ft_isascii(test5)); 
	printf("ft_isascii('%c') = %d\n", test1, isascii(test1)); 
    printf("ft_isascii('%c') = %d\n", test2, isascii(test2)); 
	printf("ft_isascii('%c') = %d\n", test3, isascii(test3)); 
    printf("ft_isascii(128) = %d\n", isascii(test4)); 
	printf("ft_isascii(-1) = %d\n", isascii(test5));

    return 0;
}
*/
